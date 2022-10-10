DROP SCHEMA IF EXISTS code_architecture CASCADE;

CREATE SCHEMA IF NOT EXISTS code_architecture;

CREATE TABLE IF NOT EXISTS code_architecture.specialty (
    id integer primary key generated always as identity,
    name text UNIQUE
);

CREATE TABLE IF NOT EXISTS code_architecture.common_item (
    id integer primary key generated always as identity,
    name text,
    amount integer,
    price numeric(8, 2),
    dosage_form text,
    manufacturer text,
    barcode text UNIQUE
    );

CREATE TABLE IF NOT EXISTS code_architecture.special_item (
    id integer primary key generated always as identity,
    name text,
    amount integer,
    price numeric(8, 2),
    dosage_form text,
    manufacturer text,
    barcode text UNIQUE,
    specialty_id integer references code_architecture.specialty(id)
    );

CREATE TABLE IF NOT EXISTS code_architecture.receipt_item (
    id integer primary key generated always as identity,
    name text,
    amount integer,
    price numeric(8, 2),
    dosage_form text,
    manufacturer text,
    barcode text UNIQUE
    );

CREATE TABLE IF NOT EXISTS code_architecture.user_account (
    id integer primary key,
    full_name text,
    phone text UNIQUE,
    password_hash text
);

CREATE TABLE IF NOT EXISTS code_architecture.doctor_account (
    id integer primary key,
    full_name text,
    phone text UNIQUE,
    password_hash text,
    specialty_id integer references code_architecture.specialty(id)
);

CREATE TABLE IF NOT EXISTS code_architecture.receipt (
    id integer primary key generated always as identity,
    user_id integer references code_architecture.user_account(id),
    item_id integer references code_architecture.receipt_item(id),
    UNIQUE (user_id, item_id)
);
