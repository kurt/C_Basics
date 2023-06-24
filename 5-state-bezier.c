#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *gnuplotPipe;

// Bezier Curve Calculation
double BezierCurve(double t, double p0, double p1, double p2)
{
    double u = 1 - t;
    double tt = t * t;
    double uu = u * u;
    double uuu = uu * u;
    double ttt = tt * t;

    double result = (uuu * p0) + (3 * uu * t * p1) + (3 * u * tt * p2) + (ttt * p2);
    return result;
}

int main()
{
    // Bezier control points for early stance phase
    double early_stance_p0 = 0.0;   // initial knee angle
    double early_stance_p1 = 15.0;  // maximum flexion angle during early stance
    double early_stance_p2 = 15;   // final knee angle during early stance

    // Bezier control points for mid stance phase
    double mid_stance_p0 = 15.0;     // initial knee angle during mid stance
    double mid_stance_p1 = 15.0;    // maximum extension angle during mid stance
    double mid_stance_p2 = 5.0;    // final knee angle during mid stance

    // Bezier control points for late stance phase
    double late_stance_p0 = 5.0;   // initial knee angle during late stance
    double late_stance_p1 = 5.0;    // maximum extension angle during late stance
    double late_stance_p2 = 30.0;    // final knee angle during late stance

    // Bezier control points for early swing phase
    double early_swing_p0 = 30.0;    // initial knee angle during early swing
    double early_swing_p1 = 40.0;   // maximum flexion angle during early swing
    double early_swing_p2 = 60.0;   // final knee angle during early swing

    // Bezier control points for late swing phase
    double late_swing_p0 = 60.0;    // initial knee angle during late swing
    double late_swing_p1 = 60.0;     // maximum extension angle during late swing
    double late_swing_p2 = 0.0;     // final knee angle during late swing

    // Time variables
    double t = 0.0;
    double dt = 0.01; // time step
    double total_time = 1.0; // total time for the gait cycle

    // Open a pipe to gnuplot for plotting
    gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe == NULL) {
        printf("Error opening pipe to gnuplot.\n");
        return -1;
    }

    // Set up the gnuplot settings
    fprintf(gnuplotPipe, "set title 'Bezier Curves - Knee Angle During Gait'\n");
    fprintf(gnuplotPipe, "set xlabel 'Time'\n");
    fprintf(gnuplotPipe, "set ylabel 'Knee Angle (degrees)'\n");
    fprintf(gnuplotPipe, "plot '-' with lines title 'Knee Angle'\n");

    float earlyStanceEndTime = 0.18;
    float midStanceEndTime = 0.4;
    float midStanceDuration = midStanceEndTime - earlyStanceEndTime;
    // Calculate and plot knee angle for each phase of the gait cycle
    while (t <= total_time)
    {
        double kneeAngle;

         if (t <= 0.2 * total_time) // Early Stance Phase
            kneeAngle = BezierCurve(t / (0.2 * total_time), early_stance_p0, early_stance_p1, early_stance_p2);
        else if (t <= 0.4 * total_time) // Mid Stance Phase
            kneeAngle = BezierCurve((t - 0.2 * total_time) / (0.2 * total_time), mid_stance_p0, mid_stance_p1, mid_stance_p2);
        else if (t <= 0.6 * total_time) // Late Stance Phase
            kneeAngle = BezierCurve((t - 0.4 * total_time) / (0.2 * total_time), late_stance_p0, late_stance_p1, late_stance_p2);
        else if (t <= 0.8 * total_time) // Early Swing Phase
            kneeAngle = BezierCurve((t - 0.6 * total_time) / (0.2 * total_time), early_swing_p0, early_swing_p1, early_swing_p2);
        else // Late Swing Phase
            kneeAngle = BezierCurve((t - 0.8 * total_time) / (0.2 * total_time), late_swing_p0, late_swing_p1, late_swing_p2);

        fprintf(gnuplotPipe, "%.2f %.2f\n", t, kneeAngle);
        t += dt;
    }

    // End of plot
    fprintf(gnuplotPipe, "e\n");

    // Close the gnuplot pipe
    pclose(gnuplotPipe);

    return 0;
}
