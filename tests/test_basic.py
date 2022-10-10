import pytest

from testsuite.databases import pgsql


# Start the tests via `make test-debug` or `make test-release`
@pytest.mark.pgsql('db-1', files=['initial_data.sql'])
async def test_db_initial_data(service_client):
    response = await service_client.get(
        '/check',
        params={'user_id': '2'},
    )
    assert response.status == 200
    assert response.text == 'Hello, Инга Садофова!\n'
