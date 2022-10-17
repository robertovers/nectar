pip install virtualenv

python -m venv venv

venv\Scripts\pip install pandas
venv\Scripts\pip install matplotlib

venv\Scripts\python reporting\report_script.py %1 %2 %3 %4
