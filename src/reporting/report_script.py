import pandas as pd
import matplotlib.pyplot as plt 

def generate_report(datafile):
    sim_data = pd.read_csv(datafile);

    time = sim_data["time"];
    nectar = sim_data["nectar"];
    pollinated = sim_data["pollinated"];

    figure, axis = plt.subplots(2, 1);

    axis[0].plot(time, nectar);
    axis[0].set_title("Nectar in Hive");

    axis[1].plot(time, pollinated);
    axis[1].set_title("No. of Pollinated Flowers");

    plt.tight_layout();
    plt.savefig("plot.pdf");

if __name__ == '__main__':
    generate_report("reporting/sim_data.csv")
