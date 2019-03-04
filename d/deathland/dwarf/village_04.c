
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The barrack","��Ӫ");
  set_long(@Long
Long
,@CLong
�����Ǿ�Ӫ���ڲ�,�кü���������(buildings)��·������,��Ȼ��Щ����
������ο�������һģһ��,����ÿһ�������ﶼ�����ر�Ĺ�\��.
����С·��Խ��Ӫ,���������˵Ĵ���.
CLong
);

set("c_item_desc",([
    "buildings":"һЩ���������Ľ���,ÿ�����������϶���һ����ӱ�ʾ�ý���\n"
                "�Ĺ�\��,���������������Ĺ�\���ƺ��Ƚ���Ȥ,�ֱ���:\n"
                "�±���������(new_trained_soldier center)\n"
                "���˹���ģʽ�о���(the college of studing trolls' attack mode)\n" 
                "������(weapons storage room)\n",
    "center":"�±���������(new_trained_soldier center)\һ��ѵ���±��ĵط�\n",
    "college":"���˹���ģʽ�о���(the college of studing trolls' attack mode)\n"
              "һ���о����˵Ĺ���ģʽ,�����ܹ��������˵��о���λ\n",
    "room":"������(weapons storage room)"    
           "�����ʽ���������ĵط� \n",    
                ]) ); 
set("exits",([
               "south":Deathland"/dwarf/village_03",
               "north":Deathland"/dwarf/village_05",
             ]));
::reset();
}

void init()
{
add_action("to_enter","enter");
}

int to_enter(string str)
{
   if (!str) return 0;
   if (str=="center") {
    this_player()->move_player(Deathland"/dwarf/center",
        ({ 
        "%s�������±�ѵ������.\n",
         "%s���������˽���.\n"}),"");
     return 1;
     }
   else if (str=="college") {
     this_player()->move_player(Deathland"/dwarf/college",
      ({
      "%s�����˾��˹���ģʽ�о���.\n",
      "%s���������˽���.\n"
       }),"");
     return 1;
     }
   else if (str=="room") {
     write("������������������ʱ��,������������.\n");
     return 1;
     
     }
   else if (str=="buildings" ||str=="building") {
     write("���������һ��������?\n");
     return 1;
     }
   else return 0;  
}
