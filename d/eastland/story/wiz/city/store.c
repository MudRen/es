#include "../../story.h"
inherit SHOP;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short("�̵�");
	set_long(@C_LONG
��ӭ���������̳ǡ�����һ���̵꣬����̵��������ο͡��������Լ�����
���˵ĵط������̵������˿�����(buy)����(sell)������(value)����ֻ��
�ι�(list)���⣬�ϰ廹Ը�⡸��ѡ�Ϊ����������ϵĶ�����������Ҫ��������
Ʒ�ø��ϰ壬���ͻ��������Ʒ����ȷ���ơ�
C_LONG
	);
	set( "exits", ([ "east" : SCITY"es.c" ]) );
	storeroom()->set( "objects", ([
		"lamp" : "/obj/lamp",
		"bandage" : "/obj/bandage",
		"map" : "/d/noden/farwind/items/pocket_map"
	]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
	set( "objects", ([
		"trashcan" : "/obj/trashcan"
	]) );
	reset();
//	replace_program(SHOP);
}
void init()
{
   ::init();
   write("\n\n�̵��ϰ�˵������ӭ���٣�������λ����Ҫ��ʲ�᣿\n\n");
}
int can_pass()
{
   write("\n\n�̵��ϰ�˵����лл�ݹˣ����´�������\n\n");
   return 0;
}