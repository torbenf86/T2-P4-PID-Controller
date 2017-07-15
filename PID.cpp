#include "PID.h"
#include <iostream>

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    _p_error = 0.0;
    _i_error = 0.0;
    _d_error = 0.0;
    _Kp = Kp;
    _Ki = Ki;
    _Kd = Kd;
    _total_error = 0.0;
}


void PID::UpdateError(double cte) {
    _p_error = cte;
    _i_error += cte;
    _d_error = cte - _prev_cte;
    _prev_cte = cte;
}

double PID::Output() {
    double y = -_p_error*_Kp -_i_error*_Ki - _d_error*_Kd;
    if (y > 1) return 1;
    else if (y <-1) return -1;
    else return y;
}
double PID::TotalError() {
    return _total_error += _p_error*_p_error;
}

void PID::twiddle() {
        _it += 1;
        int i = _it % 3;
             double err = _total_error;
            //_p[i] += _dp[i];
            if (err < _best_err) {
                _best_err = err;
                _dp[i] *= 1.1;
                _up = true;
            }
            else
            {
                if (_up) _up = false;
                else {
                _p[i] += _dp[i];
                _dp[i] *= 0.9;
                _up = true;
                }
            }
            std::cout << "Iteration" << _it << ":" << "best error" << _best_err << std::endl;
            std::cout << "Kp= " << _Kp << ", Ki= " << _Ki << ", Kd= " << _Kd << std::endl;
            if (_up) _p[i] += _dp[i];
            else _p[i] -= 2*_dp[i];

            Init(_p[0],_p[1],_p[2]);
}

