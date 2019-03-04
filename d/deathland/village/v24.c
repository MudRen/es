
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The squire of the dwarf village","���˴���Ĺ㳡");
    set_long(@Long
Long
,@CLong
��Ŀǰλ춰��˵Ĵ�ׯ�Ĵ�㳡��,���������ǳ���ƽ���������,�����Ǿ����ڴ˵�
���漰��Ϸ.������һ���ܴ��ˮ��(pool),�ǰ�������ˮ����Դ ,��ˮ����������һ��
Ʈ���ķ���(house),�㲻������Ϊ�����ܸ��ڿ��ж��������� .�������ƺ��и�СС��
��ͨ������,�������޷�ȷ���Ƿ�����Σ�յ������ڵ���.
CLong
    );
    set("c_item_desc",([
        "pool":"һ����ˮ��,��춰��˵�����ˮȡ춴˵�,���Դ�ˮ����ֹ��Ӿ.\n",
        "house":"һ��Ʈ���ķ���,��������ֵ�����,����ע��������ʱ��,�㷢����һ\n"
                "����Ĺ��ߴ��������˳���.\n"
                ]) ); 
    set("exits",([
                "east":Deathland"/village/v34",
                "south":Deathland"/village/v23",
                "down":Deathland"/village/d01",
             ]));
    create_door("down","up",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"һ��СС��ľ��",
               "c_name":"Сľ��",
               "name":"small wooden door",
               "desc":"a small wooden door",
               ]) );
    ::reset();
}
