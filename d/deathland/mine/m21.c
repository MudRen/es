
#include "../echobomber.h"

inherit ROOM;
inherit Deathland+"/mine/daemon/lever";

void create()
{
  ::create();
  set_short(" Drawf mine ","���˿��");
  set_long(@Long
Long
,@CLong
�����ǿ�ӵ��.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ��Լ�
��ľͷ�������������ݵ��Ҷ�.�ڵ���������������.ר���˿�ͨ��ʹ��.����
����\��\���˿���������.��������Ա���һ���Ƹ�(lever),�ƺ�������ʹ����.
CLong
);

set("direction","south");

set("c_item_desc",([
    "lever":"һ���Ƹ�,�ƺ���������������ķ���,�������������(pull)��.\n",
    "rail":"@@rail_c_long",
    ]) );

set("exits",([
             "northwest":Mine"/m11",
             "southeast":Mine"/m31",
             "south":Mine"/m32",
             "southwest":Mine"/m33",
             ]));

set("objects",([
    "guard":Monster"/miner02",
               ]) );

reset();
}
void init()
{
add_action("to_pull","pull");
}
int to_pull(string str)
{
    return pull_lever(this_object(),str);
}

string rail_c_long()
{
     return "Ŀǰ����ͨ��"+to_chinese( query("direction") )+"��\n";  

}

reset()
{
  string dir;
  dir=query("direction");
  ::reset();
  set("direction",dir); 
}

