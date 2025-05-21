#!/bin/bash
# Install the latest PostgreSQL packages

sudo apt install gnupg postgresql-common apt-transport-https lsb-release wget -y

# Run the PostgreSQL package setup script
sudo /usr/share/postgresql-common/pgdg/apt.postgresql.org.sh

# Opcional - If you want to do some development on PostgreSQL, add the libraries:
#sudo apt install postgresql-server-dev-16

# Add the TimescaleDB package
echo "deb https://packagecloud.io/timescale/timescaledb/ubuntu/ $(lsb_release -c -s) main" | sudo tee /etc/apt/sources.list.d/timescaledb.list

# Install the TimescaleDB GPG key
wget --quiet -O - https://packagecloud.io/timescale/timescaledb/gpgkey | sudo gpg --dearmor -o /etc/apt/trusted.gpg.d/timescaledb.gpg

# Update your local repository list
sudo apt update

# Install TimescaleDB
sudo apt install timescaledb-2-postgresql-16 postgresql-client-16 -y

# Tune your PostgreSQL instance for TimescaleDB
sudo timescaledb-tune

# Restart PostgreSQL
sudo systemctl restart postgresql
