import pandas as pd
import matplotlib.pyplot as plt 

def generate_report(datafile):
    sim_data = pd.read_csv(datafile);
    sim_data.plot();
    plt.show();

if __name__ == '__main__':
    generate_report("reporting/sim_data.csv")
