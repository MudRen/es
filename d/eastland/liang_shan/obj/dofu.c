#include <mudlib.h>

#define LIMIT_TIME 20
inherit OBJECT;

void init()
{
add_action("eat_it","eat");
}
void create()
{
	set_name("dofu","��������");
	add( "id" , ({ "dofu" }) );
	set_short("dofu" , "��������");
	set_long(".." , "��������ֵļ���������������ɫ����ˮƯ������ɫ�Ķ�����\n"
	"�ǳ����������������ó��ȳ�....\n");
   	set("unit","��");
   	set("weight", 15);
   	set("value",({ 100, "silver" }) );
}


int eat_it(string arg)
{
	object owner;
	if ( !arg || arg!="dofu")
	return notify_fail("��ʲ��??\n");
	owner = environment(this_object());
		tell_object(owner, 
			"����������������һ�������������о�һ���������������ӡ�\n"
		);
		tell_room( environment(owner), 
			owner->query("c_name")+"����һ����������������һ���ӱ��"
			"��ͨͨ��!!\n", owner
		);
		owner->receive_healing( 7+random(3) );
	remove();
        return 1;
}
