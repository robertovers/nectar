#!/bin/bash

pip install virtualenv

virtualenv venv

venv\bin\pip install pandas
venv\bin\pip install matplotlib

venv\bin\python reporting/report_script.py