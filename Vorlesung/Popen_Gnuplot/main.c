#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    double lower;
    double upper;
    double step;
    const char *function;
} Config;


#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"

int getConfig(int argc, const char **argv, Config *config) {
    int lowerCount = 0, upperCount = 0, stepCount = 0, functionCount = 0;

    for (int i = 0; i < argc - 1; ++i) {
        if (strcmp("--lower", argv[i]) == 0) {
            config->lower = atof(argv[++i]);
            ++lowerCount;
        } else if (strcmp("--upper", argv[i]) == 0) {
            config->upper = atof(argv[++i]);
            ++upperCount;
        } else if (strcmp("--step", argv[i]) == 0) {
            config->step = atof(argv[++i]);
            ++stepCount;
        } else if (strcmp("--function", argv[i]) == 0) {
            config->function = argv[++i];
            ++functionCount;
        }
    }

    if (config->upper < config->lower) {
        double temp = config->lower;
        config->lower = config->upper;
        config->upper = temp;
    }

    return -1 + (lowerCount == 1 && upperCount == 1 && stepCount == 1 && functionCount == 1);
}

#pragma clang diagnostic pop


FILE *setupPlot(Config config) {
    const char plotCall[] =
            "gnuplot -p -e \""
            "f(x) = %s; plot '-' using 1:(f($1)) w l "
            "title '[%.*lf <= x <= %.*lf; step size: %.*lf]    f(x)=%s';\"";

    size_t callLength = snprintf(
            NULL,
            0,
            plotCall,
            config.function, 3,
            config.lower, 3,
            config.upper, 3,
            config.step,
            config.function
    );

    char *call = malloc(callLength + 1);
    sprintf(
            call,
            plotCall,
            config.function, 3,
            config.lower, 3,
            config.upper, 3,
            config.step,
            config.function
    );

    FILE *plot = popen(call, "w");

    free(call);

    return plot;
}


int main(int argc, const char **argv) {
    Config config = {0, 0, 0, NULL};

    if (getConfig(argc, argv, &config)) {
        return -1;
    }

    FILE *plot = setupPlot(config);

    for (double i = config.lower; i <= config.upper; i += config.step) { // NOLINT(cert-flp30-c)
        fprintf(plot, "%lf\n", i);
    }

    pclose(plot);
    return 0;
}
