CREATE EXTENSION IF NOT EXISTS "uuid-ossp";

CREATE TABLE IF NOT EXISTS Networks (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    picture_url VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS Connects (
    user_id UUID,
    network_id INTEGER REFERENCES Networks(id) ON DELETE CASCADE,
    url VARCHAR(255) NOT NULL,
    PRIMARY KEY (user_id, network_id)
);

CREATE TABLE IF NOT EXISTS Users (
    id UUID PRIMARY KEY DEFAULT uuid_generate_v4(),
    username VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL
);