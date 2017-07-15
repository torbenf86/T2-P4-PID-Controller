#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double _p_error;
  double _i_error;
  double _d_error;

  double _total_error;

  // Helper
  double _prev_cte;
  int _it=0;
  bool _up = true;
  double _best_err = 1e40;
  double _p[3] ={0.1,1e-3,5};
  double _dp[3] = {0.1,0.1,0.1};

  /*
  * Coefficients
  */
  double _Kp;
  double _Ki;
  double _Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();

  double Output();

  void twiddle();
};

#endif /* PID_H */
