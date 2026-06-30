//#pragma once
//#include "cls_date.h"
//
//class cls_period
//{
//public:
//
//    cls_date start_date;
//    cls_date end_date;
//
//    cls_period(cls_date start_date, cls_date end_date)
//    {
//        this->start_date = start_date;
//        this->end_date = end_date;
//
//    }
//
//    /*static bool is_overlap_periods(cls_period period1, cls_period period2)
//    {
//
//        if (
//            cls_date::compare_dates(period2.end_date, period1.start_date) == cls_date ::en_dates_compare::befor
//            ||
//            cls_date::compare_dates(period2.start_date, period1.end_date) == cls_date::en_dates_compare::after
//            )
//            return false;
//        else
//            return true;
//
//    }*/
//
//    bool is_overlap_with(cls_period period2)
//    {
//        return is_overlap_periods(*this, period2);
//    }
//
//    //static bool is_date_within_period(cls_period period, cls_date date)
//    //{
//    //    return (!(cls_date::compare_dates(period.start_date, date) == cls_date::en_dates_compare::after)
//    //        && !(cls_date::compare_dates(period.end_date, date) == cls_date::en_dates_compare::befor));
//    //}
//  /*  bool is_date_within_period(cls_date date)
//    {
//        return is_date_within_period(*this, date);
//	}*/
//    void print()
//    {
//        cout << "Period Start: ";
//        start_date.print_date();
//
//        cout << "Period End: ";
//        end_date.print_date();
//
//    }
//
//};
