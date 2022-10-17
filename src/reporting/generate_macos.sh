#!/bin/bash

pip3 install virtualenv

virtualenv venv

venv/bin/pip3 install pandas
venv/bin/pip3 install matplotlib

venv/bin/python3 reporting/report_script.py $1 $2 $3 $4