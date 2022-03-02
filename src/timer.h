#pragma once


class Timer
{
        public:
        void start();
        double finish();
        double get_elapsed_time();

        private:
        double start_time = 0.0;
        double end_time = 0.0;

};
