#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{
   ::create();
   set_short( "С�칫��" );
   
   set_long(@CLONG
����ð���߹�����һ�������۵�С�칫�ң���˵�ܶ�ð�յ����϶����������
�䣬����Ľ�����һ������( table)��������������Ƥ�Ρ��Ա߷��������Ҷ
ֲ�Ϊ��������Ľ�������һ��������
CLONG);
	set( "light",1 );
	set("c_item_desc",(["table":
"���������϶����������ļ�������춾���ϸ�ĵ���������û�����ҵĸо��� \n"
"��������һ��׳�۵����С����ϻ�����һյС�ɵ��͵ƣ���Ƶĵƹ⣬ʹ��䷿��\n"
"����һ�ֹ��ϵ�ȴ��ů�ĸо����͵��Ի���һ��С��¯����ð�����Ƶ����̡�\n"	

	                   ,"censer":
"һ����ɫ�����С��¯��¯�����������������ϵĶ�����\n"	

	]));
        set( "exits", ([
                "south" : "/d/adventurer/hall/adv_libra1",
                ]) );
                
         set("no_monster",1);
         
         set("objects",(["officer" : "/d/adventurer/hall/monsters/sophia"]));
         
         create_door("south","north",([
                     "keyword":({"woodendoor","door"}),
                     "status":"closed",
                     "c_desc":"һ��СС��ľ��",
                     "c_name":"Сľ��",
                     "name":"small wooden door",
                     "desc":"a small wooden door",
                                     ]) );
         reset();                     
}
