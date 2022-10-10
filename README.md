# Домашние задание "Архитектура Кода"

У нас есть онлайн аптека, которая позволяет покупать
- разные товары (безрецептурные (в том числе простые товары вроде воды, которые к препаратам отношения не имеют),
- рецептурные (доступны любому врачу, либо пользователю у которого есть рецепт),
- специальные - доступны только для врачей конкретных специальностей например - товары для анестезиологов можно продавать только анестизиологам).

Необходимо создать отдельный сервис проверки корзины - на вход приходит запрос, который содержит id пользователя и список товаров, а в ответ выдать список позиций по которым есть проблемы. Данные о товарах и пользователях хранятся в локальной базе данных.

В сервисе необходимо создать обработчик запроса типа GET принимающий следующие парметры:

- `user_id` - Integer (айди врача или пользователя, он сквозной, т.е уникальный в рамках всей системы)
- `item_id` - список строковых значений вида `type_id` где: `type` - строковое описание типа товара, `id` - числовой идентификатор товара

Пример товара - `special_123`, `special` - тип, `123` - id, валидность структуры товара - гарантируется, валидность типа и идентификатора - нет, то есть
может прилететь товар вида ab12_qwerty.

`user_id` - гарантированно int, наличие в базе - не гаранитровано.

Пример запроса:
```curl
http://localhost:8080/check?user_id=123&item_id=special_26&item_id=common_25
```


Вся нужная информация будет лежать в базе данных.

> **Необходимы для инициализации базы данных в папке ./postgresql
> Схема нарисована в pharmacy_er.png, лежит там же где и readme, настоятельно рекомендую начать с ее изучения**.

Пользователи относятся к двум категориям - обычные пользователи и врачи, лежат в разных таблицах с разными схемами. Определить кем является пользователь нужно реализуя какую то архитектурную хитрость и обосновать ее выбор - любую на свое усмотрение или не использовать вовсе но обосновать почему этого делать не стоит.

Задача получения пользователя сводится к тому, чтобы попытаться найти его в 1 источнике, если не вышло попытаться найти в другом источнике (в контексте задачи источники это разные таблицы). Ищем либо пока не найдем, либо пока не проверим все источники (в нашем случае их 2, но надо понимать, что в будущем может быть больше). Надо разрабатывать код с прицелом на увеличение числа источников данных и типов пользователей.


Необходимо описать стратегии валидации товаров - проверка рецептурных, проверка специальных товаров, и проверка простых товаров.

Перед валидацией необходимо определить категорию товара, и исходя из категории определить как его проверять.

Товары лежат в разных таблицах, рецепты для пользователей лежат в отдельной таблице.

Решение нужно реализовывать таким образом, чтобы при добавлении нового вида товаров потребовалось сделать минимум модификаций в уже существующий код.


Категории товаров - рецептурные, безрецептурные, специальные (безрецептурные и простые лежат в одной таблице и имеют один тип - `common`).

Специальные товары - тип `special`<br>
Обычные товары - `common`<br>
Рецептурные - `receipt`<br>

При парсинге категории товара нужно приводить ее к нижнему регистру и возвращать в нижнем регистре.

Товары хранятся в разных таблицах. Определить, где искать товар можно по типу (`special/common/receipt`). Из базы можно получить значение по id (целочисленная часть).

Список рецептов по пользователям реализован через промежуточную таблицу, связывающую рецептурные товары и пользователей.

В таблице специальных товаров описано к какой сфере они относятся (например, товары доступные к покупке только хирургам или только анестезиологам).


**Возможные ситуации описаны ниже.**


Структура ответа:

```
200 OK
[
    {
        "item_id": string,
        "problem": string
    }
]
```

Формат `item_id` - такой же как на входе, в нижнем регистре. Если прилетел `Common_123` - вернуть `common_123`. Если с товаром все окей, и с пользователем все окей, то ничего не нужно возвращать. В ответ вписываем только проблемные товары и их причины.


**Обработка краевых случаев**

Для каждого вида ошибки использовать свой код в ответе.

Коды ошибок для ответов:


| Ошибка                                                                             |    Код ответа  (problem)    |
|------------------------------------------------------------------------------------|:---------------------------:|
| Ошибка парсинга категории товара - категория не найдена, в этом случае id не важен |       WRONG_CATEGORY        |
| Ошибка парсинга id товара   (категория спарсилась правильно - но id кривой)        |    INCORRECT_ITEM_ID        |
| Товар не найден (тип пользователя не важен)                                        |       ITEM_NOT_FOUND        |
| Пользователь не найден, товар можно продать                                        |           NO_USER           |
| Пользователь не найден, товар рецептурный                                          |     NO_USER_NO_RECEIPT      |
| Пользователь не найден, товар специальный                                          |    NO_USER_SPECIAL_ITEM     |
| Пользователь найден, товар рецептурный, у пользователя нет рецепта                 |         NO_RECEIPT          |
| Пользователь найден, товар спец. назначения                                        |       ITEM_IS_SPECIAL       |
| Пользователь врач, товар специальный, но не совпал по сфере работы врача           | ITEM_SPECIAL_WRONG_SPECIFIC |


**Про тесты**


Мы не требуем писать тесты в этом задании. Как убедиться в корректности работы вашего приложения вы решаете сами.

## Download and Build

To create your own userver-based service follow the following steps:

1. Press the green "Use this template button" at the top of this github page
2. Clone the service `git clone your-service-repo && cd your-service-repo`
3. Feel free to tweak, adjust or fully rewrite the source code of your service.


## Makefile

Makefile contains typicaly useful targets for development:

* `make build-debug` - debug build of the service with all the assertions and sanitizers enabled
* `make build-release` - release build of the service with LTO
* `make test-debug` - does a `make build-debug` and runs all the tests on the result
* `make test-release` - does a `make build-release` and runs all the tests on the result
* `make service-start-debug` - builds the service in debug mode and starts it
* `make service-start-release` - builds the service in release mode and starts it
* `make` or `make all` - builds and runs all the tests in release and debug modes
* `make format` - autoformat all the C++ and Python sources
* `make clean-` - cleans the object files
* `make dist-clean` - clean all, including the CMake cached configurations
* `make install` - does a `make build-release` and runs install in directory set in environment `PREFIX`
* `make install-debug` - does a `make build-debug` and runs install in directory set in environment `PREFIX`
* `make docker-COMMAND` - run `make COMMAND` in docker environment
* `make docker-build-debug` - debug build of the service with all the assertions and sanitizers enabled in docker environment
* `make docker-test-debug` - does a `make build-debug` and runs all the tests on the result in docker environment
* `make docker-start-service` - does a `make install` and runs service in docker environment
* `make docker-start-service-debug` - does a `make install-debug` and runs service in docker environment
* `make docker-clean-data` - stop docker containers and clean database data

Edit `Makefile.local` to change the default configuration and build options.


## License

The original template is distributed under the [Apache-2.0 License](https://github.com/userver-framework/userver/blob/develop/LICENSE)
and [CLA](https://github.com/userver-framework/userver/blob/develop/CONTRIBUTING.md). Services based on the template may change
the license and CLA.
