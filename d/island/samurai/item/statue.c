#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("statue","�ȿ��贵���");
	add( "id" , ({ "statue" }) );
	set_short("statue" , "�ȿ��贵���");
	set_long(@AAA
һ������൱�����ĵ�����ϸһ��ԭ���Ǹ��ȿ��贵������治����
һ����̴�ʦ���Ҿ��̵ģ���������������Ҫ������Ϊ��������������
��С��������Ϊ���������أ���	
AAA
	);
   	set("unit","��");
   	set("weight", 20);
   	set("nakoruru_statue",1);
   	set("value",({ 1, "silver" }) );
}

