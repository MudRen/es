
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("swamp of GreyIsland","�Ұ�֮��������");
  set_long(@Long
Long
,@CLong
һ�������������, �������ƺ��������µ��������������ȥ, �����С�Ľ���
���ÿһ��. ���������ˮ�ƺ�����, �����������Ҳ��������ȫ����ס��. ����
���Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ����������������. ��ϸ��
���ŵ��ƺ�����һ����ֵ�Ģ��(mushroom)������.
CLong
);


set("exits",([
     "south":Deathland"/island/swamp15",
     ]) );
set("item_func",([
    "mushroom":"look_mushroom",
    ]) );
set("exit_invisble",1);     

::reset();
}


void init()
{
    add_action("to_pluck","pluck");
}

int to_pluck(string str)
{
    object *items;
    int i;
    if (!str||str!="mushroom") return 0;
    
    items=all_inventory(this_player());
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ){
          write("��ժ��һЩĢ��������ĺں�����.\n");
          items[i]->set("quest_item/grey_mushroom",1);
          return 1;
          }
     write("�㿴�˿���ЩĢ��,�ƺ�û��������;, ˳�ְ���������.\n");
     return 1;     
}

int look_mushroom()
{
    this_player()->set_explore("deathland#24");
    write("һ����ֵĻ�ɫĢ��, �ƺ�����ժ(pluck)һЩ������\n");
    return 1;
}
