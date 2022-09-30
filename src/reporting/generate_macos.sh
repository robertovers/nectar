#!/bin/bash

pip3 install virtualenv

virtualenv venv

venv/bin/pip3 install pandas

venv/bin/python3 reporting/report_script.py