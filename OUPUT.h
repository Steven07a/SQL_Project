#ifndef Z_OUTPUT_H_
#define Z_OUTPUT_H_

/*
USER INPUT RUN

=====================SQL=====================
create table test fields first,last,major,age
=====================SQL=====================
insert into test values Richard,Harris,CS,23
=====================SQL=====================
insert into test values Bob,Harris,CS,30
=====================SQL=====================
insert into test values Jack,Smith,CS,40
=====================SQL=====================
insert into test values Steven,Herrera,CS,25
=====================SQL=====================
select first,last from test

test:
first last
Bob   Harris
Jack  Smith
Richard Harris
Steven Herrera

=====================SQL=====================
select first,last,major from test

test:
first last major
Bob   Harris CS
Jack  Smith CS
Richard Harris CS
Steven Herrera CS

=====================SQL=====================
select first,last,age from test

test:
first last age
Bob   Harris 30
Jack  Smith 40
Richard Harris 23
Steven Herrera 25

=====================SQL=====================
select * from test

test:
first last major age
Richard Harris CS 23
Bob   Harris CS 30
Jack  Smith CS 40
Steven Herrera CS 25

=====================SQL=====================
select first,last,age from test where age > 30

test:
first last age
Jack  Smith 40

=====================SQL=====================
select first,last,age from test where age >= 30

test:
first last age
Bob   Harris 30
Jack  Smith 40

=====================SQL=====================
select first,last,age from test where age < 30

test:
first last age
Richard Harris 23
Steven Herrera 25

=====================SQL=====================
select first,last,age from test where age <= 30

test:
first last age
Richard Harris 23
Steven Herrera 25
Bob   Harris 30

=====================SQL=====================
exit

C:\Users\Steven_dev\Desktop\CS_Stuff\SQLClass\SQLClass\Debug\SQLClass.exe (process 8140) exited with code 0.
Press any key to close this window . . .

BATCH RUN

SQL> batch t2.txt
//****************************************************************************
//              CREATE TABLES AND INSERT RECORDS
//****************************************************************************


[0] make table employee cols: last first dep salary year
Table employee created. cols: last first dep salary year
SQL: DONE.

[1] insert into employee values: Blow Joe CS 100000 2018
SQL: DONE.

[2] insert into employee values: Blow JoAnn Physics 200000 2016
SQL: DONE.

[3] insert into employee values: Johnson Jack HR 150000 2014
SQL: DONE.

[4] insert into employee values: Johnson Jimmy Chemistry 140000 2018
SQL: DONE.

[5] insert into employee values: Yao Jimmy Math 145000 2014
SQL: DONE.

[6] insert into employee values: Yao Flo CS 147000 2012
SQL: DONE.

[7] insert into employee values: Yang Bo CS 160000 2013
SQL: DONE.

[8] insert into employee values: Jackson Flo Math 165000 2017
SQL: DONE.

[9] insert into employee values: Jackson Bo Chemistry 130000 2011
SQL: DONE.

[10] insert into employee values: Jackson Billy Math 170000 2017
SQL: DONE.

[11] insert into employee values: Johnson Mary Ann Math 165000 2014
SQL: DONE.

[12] insert into employee values: Johnson Billy Bob Physics 142000 2014
SQL: DONE.

[13] insert into employee values: Johnson Billy Phys Ed 102000 2014
SQL: DONE.

[14] insert into employee values: Van Gogh Vincent Art 240000 2015
SQL: DONE.

[15] insert into employee values: Van Gogh Vincent CS 245000 2015
SQL: DONE.

[16] insert into employee values: Van Gogh Jim Bob Phys Ed 230000 2010
SQL: DONE.


[17] select  * from employee
Table name employee, records: 16
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2        Johnson           Jack             HR         150000           2014
     3        Johnson          Jimmy      Chemistry         140000           2018
     4            Yao          Jimmy           Math         145000           2014
     5            Yao            Flo             CS         147000           2012
     6           Yang             Bo             CS         160000           2013
     7        Jackson            Flo           Math         165000           2017
     8        Jackson             Bo      Chemistry         130000           2011
     9        Jackson          Billy           Math         170000           2017
    10        Johnson       Mary Ann           Math         165000           2014
    11        Johnson      Billy Bob        Physics         142000           2014
    12        Johnson          Billy        Phys Ed         102000           2014
    13       Van Gogh        Vincent            Art         240000           2015
    14       Van Gogh        Vincent             CS         245000           2015
    15       Van Gogh        Jim Bob        Phys Ed         230000           2010

SQL: DONE.


[18] make table student cols: fname lname major age company
Table student created. cols: fname lname major age company
SQL: DONE.

[19] insert into student values: Flo Yao CS 20 Google
SQL: DONE.

[20] insert into student values: Bo Yang CS 28 Microsoft
SQL: DONE.

[21] insert into student values: Sammuel L. Jackson CS 40 Uber
SQL: DONE.

[22] insert into student values: Flo Jackson Math 21 Google
SQL: DONE.

[23] insert into student values: Greg Pearson Physics 20 Amazon
SQL: DONE.

[24] insert into student values: Jim Bob Smith Math 23 Verizon
SQL: DONE.

[25] insert into student values: Calvin Woo Physics 22 Uber
SQL: DONE.

[26] insert into student values: Anna Grace Del Rio CS 22 USAF
SQL: DONE.

[27] insert into student values: Teresa Mae Gowers Chemistry 22 Verizon
SQL: DONE.

[28] insert into student values: Alex Smith Gender Studies 53 Amazon
SQL: DONE.


[29] select  * from student
Table name student, records: 10
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2     Sammuel L.        Jackson             CS             40           Uber
     3            Flo        Jackson           Math             21         Google
     4           Greg        Pearson        Physics             20         Amazon
     5        Jim Bob          Smith           Math             23        Verizon
     6         Calvin            Woo        Physics             22           Uber
     7     Anna Grace        Del Rio             CS             22           USAF
     8     Teresa Mae         Gowers      Chemistry             22        Verizon
     9           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.



//****************************************************************************
//              SIMPLE SELECT:
//****************************************************************************


[30] select  * from student
Table name student, records: 10
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2     Sammuel L.        Jackson             CS             40           Uber
     3            Flo        Jackson           Math             21         Google
     4           Greg        Pearson        Physics             20         Amazon
     5        Jim Bob          Smith           Math             23        Verizon
     6         Calvin            Woo        Physics             22           Uber
     7     Anna Grace        Del Rio             CS             22           USAF
     8     Teresa Mae         Gowers      Chemistry             22        Verizon
     9           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


//------- simple strings -------------------

[31] select * from student where lname = Jackson
Table name student, records: 2
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1            Flo        Jackson           Math             21         Google

SQL: DONE.


[32] select * from student where major = CS
Table name student, records: 4
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2     Sammuel L.        Jackson             CS             40           Uber
     3     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[33] select * from student where company = Uber
Table name student, records: 2
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1         Calvin            Woo        Physics             22           Uber

SQL: DONE.


//----- quoted strings ---------------------

[34] select * from student where lname = Del Rio
Table name student, records: 1
record          fname          lname          major            age        company
     0     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[35] select * from student where fname = Jim Bob
Table name student, records: 1
record          fname          lname          major            age        company
     0        Jim Bob          Smith           Math             23        Verizon

SQL: DONE.


[36] select * from student where fname = Anna Grace
Table name student, records: 1
record          fname          lname          major            age        company
     0     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[37] select * from student where fname = Teresa Mae
Table name student, records: 1
record          fname          lname          major            age        company
     0     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


//-------- non-existing string ------------------

[38] select * from student where lname = Does Not Exist
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


//****************************************************************************
//              RELATIONAL OPERATORS:
//****************************************************************************

//.................
//:Greater Than   :
//.................

[39] select * from student where lname > Yang
Table name student, records: 1
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google

SQL: DONE.


[40] select * from student where major > Math
Table name student, records: 2
record          fname          lname          major            age        company
     0           Greg        Pearson        Physics             20         Amazon
     1         Calvin            Woo        Physics             22           Uber

SQL: DONE.


[41] select * from student where fname > Sammuel L.
Table name student, records: 1
record          fname          lname          major            age        company
     0     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


[42] select * from employee where salary > 200000
Table name employee, records: 3
record           last          first            dep         salary           year
     0       Van Gogh        Jim Bob        Phys Ed         230000           2010
     1       Van Gogh        Vincent            Art         240000           2015
     2       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.


[43] select * from employee where dep > Chemistry
Table name employee, records: 9
record           last          first            dep         salary           year
     0        Johnson           Jack             HR         150000           2014
     1            Yao          Jimmy           Math         145000           2014
     2        Jackson            Flo           Math         165000           2017
     3        Jackson          Billy           Math         170000           2017
     4        Johnson       Mary Ann           Math         165000           2014
     5        Johnson          Billy        Phys Ed         102000           2014
     6       Van Gogh        Jim Bob        Phys Ed         230000           2010
     7           Blow          JoAnn        Physics         200000           2016
     8        Johnson      Billy Bob        Physics         142000           2014

SQL: DONE.


[44] select * from employee where last > Jackson
Table name employee, records: 11
record           last          first            dep         salary           year
     0        Johnson           Jack             HR         150000           2014
     1        Johnson          Jimmy      Chemistry         140000           2018
     2        Johnson       Mary Ann           Math         165000           2014
     3        Johnson      Billy Bob        Physics         142000           2014
     4        Johnson          Billy        Phys Ed         102000           2014
     5       Van Gogh        Vincent            Art         240000           2015
     6       Van Gogh        Vincent             CS         245000           2015
     7       Van Gogh        Jim Bob        Phys Ed         230000           2010
     8           Yang             Bo             CS         160000           2013
     9            Yao          Jimmy           Math         145000           2014
    10            Yao            Flo             CS         147000           2012

SQL: DONE.


[45] select * from employee where first > Billy Bob
Table name employee, records: 13
record           last          first            dep         salary           year
     0           Yang             Bo             CS         160000           2013
     1        Jackson             Bo      Chemistry         130000           2011
     2            Yao            Flo             CS         147000           2012
     3        Jackson            Flo           Math         165000           2017
     4        Johnson           Jack             HR         150000           2014
     5       Van Gogh        Jim Bob        Phys Ed         230000           2010
     6        Johnson          Jimmy      Chemistry         140000           2018
     7            Yao          Jimmy           Math         145000           2014
     8           Blow          JoAnn        Physics         200000           2016
     9           Blow            Joe             CS         100000           2018
    10        Johnson       Mary Ann           Math         165000           2014
    11       Van Gogh        Vincent            Art         240000           2015
    12       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.



//. . . . . . . . . . . . . (Greater Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .

[46] select * from student where age > 50
Table name student, records: 1
record          fname          lname          major            age        company
     0           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[47] select * from student where age > 35
Table name student, records: 2
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[48] select * from student where fname > T
Table name student, records: 1
record          fname          lname          major            age        company
     0     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


[49] select * from employee where salary > 130000
Table name employee, records: 13
record           last          first            dep         salary           year
     0        Johnson          Jimmy      Chemistry         140000           2018
     1        Johnson      Billy Bob        Physics         142000           2014
     2            Yao          Jimmy           Math         145000           2014
     3            Yao            Flo             CS         147000           2012
     4        Johnson           Jack             HR         150000           2014
     5           Yang             Bo             CS         160000           2013
     6        Jackson            Flo           Math         165000           2017
     7        Johnson       Mary Ann           Math         165000           2014
     8        Jackson          Billy           Math         170000           2017
     9           Blow          JoAnn        Physics         200000           2016
    10       Van Gogh        Jim Bob        Phys Ed         230000           2010
    11       Van Gogh        Vincent            Art         240000           2015
    12       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.


[50] select * from employee where year > 2009
Table name employee, records: 16
record           last          first            dep         salary           year
     0       Van Gogh        Jim Bob        Phys Ed         230000           2010
     1        Jackson             Bo      Chemistry         130000           2011
     2            Yao            Flo             CS         147000           2012
     3           Yang             Bo             CS         160000           2013
     4        Johnson           Jack             HR         150000           2014
     5            Yao          Jimmy           Math         145000           2014
     6        Johnson       Mary Ann           Math         165000           2014
     7        Johnson      Billy Bob        Physics         142000           2014
     8        Johnson          Billy        Phys Ed         102000           2014
     9       Van Gogh        Vincent            Art         240000           2015
    10       Van Gogh        Vincent             CS         245000           2015
    11           Blow          JoAnn        Physics         200000           2016
    12        Jackson            Flo           Math         165000           2017
    13        Jackson          Billy           Math         170000           2017
    14           Blow            Joe             CS         100000           2018
    15        Johnson          Jimmy      Chemistry         140000           2018

SQL: DONE.


//. . . . . . . . . . . . . (Greater than: last item) . . . . . . . . . . . . . . . . . .

[51] select * from student where age > 53
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[52] select * from student where lname > Yao
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[53] select * from student where fname > Teresa Mae
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[54] select * from employee where last > Van Gogh
Table name employee, records: 3
record           last          first            dep         salary           year
     0           Yang             Bo             CS         160000           2013
     1            Yao          Jimmy           Math         145000           2014
     2            Yao            Flo             CS         147000           2012

SQL: DONE.


[55] select * from employee where first > Vincent
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[56] select * from employee where salary > 260000
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


//. . . . . . . . . . . . . (Greater Than: Passed last item) . . . . . . . . . . . . . . . . . . . . .

[57] select * from student where age > 54
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[58] select * from student where lname > Zoolander
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[59] select * from employee where last > Zoolaner
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[60] select * from employee where first > Xu
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


//.................
//:Greater Equal  :
//.................

[61] select * from student where lname >= Yang
Table name student, records: 2
record          fname          lname          major            age        company
     0             Bo           Yang             CS             28      Microsoft
     1            Flo            Yao             CS             20         Google

SQL: DONE.


[62] select * from student where fname >= Sammuel L.
Table name student, records: 2
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


[63] select * from student where age >= 40
Table name student, records: 2
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.

//. . . . . .  (Greater Equal non-existing: ) . . . . . . . . . . .

[64] select * from employee where last >= Jack
Table name employee, records: 14
record           last          first            dep         salary           year
     0        Jackson            Flo           Math         165000           2017
     1        Jackson             Bo      Chemistry         130000           2011
     2        Jackson          Billy           Math         170000           2017
     3        Johnson           Jack             HR         150000           2014
     4        Johnson          Jimmy      Chemistry         140000           2018
     5        Johnson       Mary Ann           Math         165000           2014
     6        Johnson      Billy Bob        Physics         142000           2014
     7        Johnson          Billy        Phys Ed         102000           2014
     8       Van Gogh        Vincent            Art         240000           2015
     9       Van Gogh        Vincent             CS         245000           2015
    10       Van Gogh        Jim Bob        Phys Ed         230000           2010
    11           Yang             Bo             CS         160000           2013
    12            Yao          Jimmy           Math         145000           2014
    13            Yao            Flo             CS         147000           2012

SQL: DONE.


[65] select * from employee where first >= Bill
Table name employee, records: 16
record           last          first            dep         salary           year
     0        Jackson          Billy           Math         170000           2017
     1        Johnson          Billy        Phys Ed         102000           2014
     2        Johnson      Billy Bob        Physics         142000           2014
     3           Yang             Bo             CS         160000           2013
     4        Jackson             Bo      Chemistry         130000           2011
     5            Yao            Flo             CS         147000           2012
     6        Jackson            Flo           Math         165000           2017
     7        Johnson           Jack             HR         150000           2014
     8       Van Gogh        Jim Bob        Phys Ed         230000           2010
     9        Johnson          Jimmy      Chemistry         140000           2018
    10            Yao          Jimmy           Math         145000           2014
    11           Blow          JoAnn        Physics         200000           2016
    12           Blow            Joe             CS         100000           2018
    13        Johnson       Mary Ann           Math         165000           2014
    14       Van Gogh        Vincent            Art         240000           2015
    15       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.


[66] select * from employee where salary >= 235000
Table name employee, records: 2
record           last          first            dep         salary           year
     0       Van Gogh        Vincent            Art         240000           2015
     1       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.



//.................
//:Less Than      :
//.................


//. . . . . . . . . . . . . (Less Than: Non-existing) . . . . . . . . . . . . . . . . . . . . .

[67] select * from student where lname < Jackson
Table name student, records: 2
record          fname          lname          major            age        company
     0     Anna Grace        Del Rio             CS             22           USAF
     1     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


[68] select * from student where major < Math
Table name student, records: 6
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2     Sammuel L.        Jackson             CS             40           Uber
     3     Anna Grace        Del Rio             CS             22           USAF
     4     Teresa Mae         Gowers      Chemistry             22        Verizon
     5           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[69] select * from student where fname < Jim Bob
Table name student, records: 7
record          fname          lname          major            age        company
     0           Alex          Smith Gender Studies             53         Amazon
     1     Anna Grace        Del Rio             CS             22           USAF
     2             Bo           Yang             CS             28      Microsoft
     3         Calvin            Woo        Physics             22           Uber
     4            Flo            Yao             CS             20         Google
     5            Flo        Jackson           Math             21         Google
     6           Greg        Pearson        Physics             20         Amazon

SQL: DONE.


[70] select * from employee where salary < 200000
Table name employee, records: 12
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1        Johnson          Billy        Phys Ed         102000           2014
     2        Jackson             Bo      Chemistry         130000           2011
     3        Johnson          Jimmy      Chemistry         140000           2018
     4        Johnson      Billy Bob        Physics         142000           2014
     5            Yao          Jimmy           Math         145000           2014
     6            Yao            Flo             CS         147000           2012
     7        Johnson           Jack             HR         150000           2014
     8           Yang             Bo             CS         160000           2013
     9        Jackson            Flo           Math         165000           2017
    10        Johnson       Mary Ann           Math         165000           2014
    11        Jackson          Billy           Math         170000           2017

SQL: DONE.


[71] select * from employee where dep < CS
Table name employee, records: 1
record           last          first            dep         salary           year
     0       Van Gogh        Vincent            Art         240000           2015

SQL: DONE.


[72] select * from employee where last < Jackson
Table name employee, records: 2
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016

SQL: DONE.


[73] select * from employee where first < Billy Bob
Table name employee, records: 2
record           last          first            dep         salary           year
     0        Jackson          Billy           Math         170000           2017
     1        Johnson          Billy        Phys Ed         102000           2014

SQL: DONE.


//. . . . . . . . . . . . . (Less than: first item) . . . . . . . . . . . . . . . . . .

[74] select * from student where age < 20
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[75] select * from student where lname < Del Rio
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[76] select * from student where fname < Alex
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[77] select * from employee where last < Blow
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[78] select * from employee where first < Billy
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[79] select * from employee where salary < 100000
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.



//. . . . . . . . . . . . . (Less Than: before first item) . . . . . . . . . . . . . . . . . . . . .


[80] select * from student where age < 19
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[81] select * from student where lname < Adams
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[82] select * from student where fname < Adam
Table name student, records: 0
record          fname          lname          major            age        company

SQL: DONE.


[83] select * from employee where last < Alex
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[84] select * from employee where first < Avory
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.


[85] select * from employee where dep < Alchemy
Table name employee, records: 0
record           last          first            dep         salary           year

SQL: DONE.



//.................
//:Less Equal     :
//.................


[86] select * from student where lname <= Smith
Table name student, records: 7
record          fname          lname          major            age        company
     0     Anna Grace        Del Rio             CS             22           USAF
     1     Teresa Mae         Gowers      Chemistry             22        Verizon
     2     Sammuel L.        Jackson             CS             40           Uber
     3            Flo        Jackson           Math             21         Google
     4           Greg        Pearson        Physics             20         Amazon
     5        Jim Bob          Smith           Math             23        Verizon
     6           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[87] select * from student where fname <= Greg
Table name student, records: 7
record          fname          lname          major            age        company
     0           Alex          Smith Gender Studies             53         Amazon
     1     Anna Grace        Del Rio             CS             22           USAF
     2             Bo           Yang             CS             28      Microsoft
     3         Calvin            Woo        Physics             22           Uber
     4            Flo            Yao             CS             20         Google
     5            Flo        Jackson           Math             21         Google
     6           Greg        Pearson        Physics             20         Amazon

SQL: DONE.


[88] select * from student where age <= 40
Table name student, records: 9
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1           Greg        Pearson        Physics             20         Amazon
     2            Flo        Jackson           Math             21         Google
     3         Calvin            Woo        Physics             22           Uber
     4     Anna Grace        Del Rio             CS             22           USAF
     5     Teresa Mae         Gowers      Chemistry             22        Verizon
     6        Jim Bob          Smith           Math             23        Verizon
     7             Bo           Yang             CS             28      Microsoft
     8     Sammuel L.        Jackson             CS             40           Uber

SQL: DONE.


//. . . . . .  (Less Equal non-existing: ) . . . . . . . . . . .

[89] select * from employee where last <= Peach
Table name employee, records: 10
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2        Jackson            Flo           Math         165000           2017
     3        Jackson             Bo      Chemistry         130000           2011
     4        Jackson          Billy           Math         170000           2017
     5        Johnson           Jack             HR         150000           2014
     6        Johnson          Jimmy      Chemistry         140000           2018
     7        Johnson       Mary Ann           Math         165000           2014
     8        Johnson      Billy Bob        Physics         142000           2014
     9        Johnson          Billy        Phys Ed         102000           2014

SQL: DONE.


[90] select * from employee where first <= Gary
Table name employee, records: 7
record           last          first            dep         salary           year
     0        Jackson          Billy           Math         170000           2017
     1        Johnson          Billy        Phys Ed         102000           2014
     2        Johnson      Billy Bob        Physics         142000           2014
     3           Yang             Bo             CS         160000           2013
     4        Jackson             Bo      Chemistry         130000           2011
     5            Yao            Flo             CS         147000           2012
     6        Jackson            Flo           Math         165000           2017

SQL: DONE.


[91] select * from employee where salary <= 23500
Table name employee, records: 14
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1        Johnson          Billy        Phys Ed         102000           2014
     2        Jackson             Bo      Chemistry         130000           2011
     3        Johnson          Jimmy      Chemistry         140000           2018
     4        Johnson      Billy Bob        Physics         142000           2014
     5            Yao          Jimmy           Math         145000           2014
     6            Yao            Flo             CS         147000           2012
     7        Johnson           Jack             HR         150000           2014
     8           Yang             Bo             CS         160000           2013
     9        Jackson            Flo           Math         165000           2017
    10        Johnson       Mary Ann           Math         165000           2014
    11        Jackson          Billy           Math         170000           2017
    12           Blow          JoAnn        Physics         200000           2016
    13       Van Gogh        Jim Bob        Phys Ed         230000           2010

SQL: DONE.


//****************************************************************************
//              LOGICAL OPERATORS
//****************************************************************************


//.................
//:AND            :
//.................


[92] select * from student where fname = Flo and lname = Yao
Table name student, records: 1
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google

SQL: DONE.


[93] select * from student where major = CS and age < 25
Table name student, records: 2
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[94] select * from student where major < Math and age > 25
Table name student, records: 3
record          fname          lname          major            age        company
     0             Bo           Yang             CS             28      Microsoft
     1     Sammuel L.        Jackson             CS             40           Uber
     2           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[95] select * from employee where dep = CS and salary > 150000
Table name employee, records: 2
record           last          first            dep         salary           year
     0           Yang             Bo             CS         160000           2013
     1       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.


[96] select * from employee where last = Jackson and year < 2015
Table name employee, records: 1
record           last          first            dep         salary           year
     0        Jackson             Bo      Chemistry         130000           2011

SQL: DONE.


[97] select * from employee where last = Johnson and year >= 2014
Table name employee, records: 5
record           last          first            dep         salary           year
     0        Johnson           Jack             HR         150000           2014
     1        Johnson          Jimmy      Chemistry         140000           2018
     2        Johnson       Mary Ann           Math         165000           2014
     3        Johnson      Billy Bob        Physics         142000           2014
     4        Johnson          Billy        Phys Ed         102000           2014

SQL: DONE.



//.................
//:OR            :
//.................

[98] select * from student where fname = Flo or lname = Jackson
Table name student, records: 3
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1     Sammuel L.        Jackson             CS             40           Uber
     2            Flo        Jackson           Math             21         Google

SQL: DONE.


[99] select * from student where age >= 40 or company = Verizon
Table name student, records: 4
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1        Jim Bob          Smith           Math             23        Verizon
     2     Teresa Mae         Gowers      Chemistry             22        Verizon
     3           Alex          Smith Gender Studies             53         Amazon

SQL: DONE.


[100] select * from employee where first = Bo or last = Johnson
Table name employee, records: 7
record           last          first            dep         salary           year
     0        Johnson           Jack             HR         150000           2014
     1        Johnson          Jimmy      Chemistry         140000           2018
     2           Yang             Bo             CS         160000           2013
     3        Jackson             Bo      Chemistry         130000           2011
     4        Johnson       Mary Ann           Math         165000           2014
     5        Johnson      Billy Bob        Physics         142000           2014
     6        Johnson          Billy        Phys Ed         102000           2014

SQL: DONE.


[101] select * from employee where year >= 2015 or dep = CS
Table name employee, records: 9
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2        Johnson          Jimmy      Chemistry         140000           2018
     3            Yao            Flo             CS         147000           2012
     4           Yang             Bo             CS         160000           2013
     5        Jackson            Flo           Math         165000           2017
     6        Jackson          Billy           Math         170000           2017
     7       Van Gogh        Vincent            Art         240000           2015
     8       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.



//.................
//:OR AND         :
//.................

[102] select * from student where fname = Flo or major = CS and age <= 23
Table name student, records: 3
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1            Flo        Jackson           Math             21         Google
     2     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[103] select * from student where lname = Jackson or age < 23 and company > Uber
Table name student, records: 3
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1            Flo        Jackson           Math             21         Google
     2     Teresa Mae         Gowers      Chemistry             22        Verizon

SQL: DONE.


[104] select * from employee where last = Van Gogh or last = Jackson and salary >= 165000
Table name employee, records: 5
record           last          first            dep         salary           year
     0        Jackson            Flo           Math         165000           2017
     1        Jackson          Billy           Math         170000           2017
     2       Van Gogh        Vincent            Art         240000           2015
     3       Van Gogh        Vincent             CS         245000           2015
     4       Van Gogh        Jim Bob        Phys Ed         230000           2010

SQL: DONE.



//.................
//:AND OR AND     :
//.................


[105] select * from student where age < 30 and major = CS or major = Physics and company = Amazon
Table name student, records: 4
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2           Greg        Pearson        Physics             20         Amazon
     3     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[106] select * from student where age <= 40 and company = Uber or major = CS and company = Google
Table name student, records: 3
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1     Sammuel L.        Jackson             CS             40           Uber
     2         Calvin            Woo        Physics             22           Uber

SQL: DONE.


[107] select * from employee where dep = CS and salary >= 160000 or year > 2014 and last = Van Gogh
Table name employee, records: 3
record           last          first            dep         salary           year
     0           Yang             Bo             CS         160000           2013
     1       Van Gogh        Vincent            Art         240000           2015
     2       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.



//.................
//:OR AND OR      :
//.................


[108] select * from student where lname = Yang or major = CS and age < 23 or company = Google
Table name student, records: 4
record          fname          lname          major            age        company
     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2            Flo        Jackson           Math             21         Google
     3     Anna Grace        Del Rio             CS             22           USAF

SQL: DONE.


[109] select * from student where major = Physics or major = Math and company = Google or lname = Jackson
Table name student, records: 4
record          fname          lname          major            age        company
     0     Sammuel L.        Jackson             CS             40           Uber
     1            Flo        Jackson           Math             21         Google
     2           Greg        Pearson        Physics             20         Amazon
     3         Calvin            Woo        Physics             22           Uber

SQL: DONE.


[110] select * from employee where dep = CS or year > 2014 and year < 2018 or salary >= 265000
Table name employee, records: 8
record           last          first            dep         salary           year
     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2            Yao            Flo             CS         147000           2012
     3           Yang             Bo             CS         160000           2013
     4        Jackson            Flo           Math         165000           2017
     5        Jackson          Billy           Math         170000           2017
     6       Van Gogh        Vincent            Art         240000           2015
     7       Van Gogh        Vincent             CS         245000           2015

SQL: DONE.













C:\Users\Steven_dev\Desktop\CS_Stuff\SQLClass\SQLClass\Debug\SQLClass.exe (process 21640) exited with code 0.
Press any key to close this window . . .


*/

#endif // !Z_OUTPUT_H_
