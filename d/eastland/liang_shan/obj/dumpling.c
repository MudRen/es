#include <mudlib.h>
#define FRESH_TIME 500

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("dumpling","����");
	add( "id" , ({ "dumpling" }) );
	set_short("a dumpling." , "����");
	set_long(".." , 
		"Ƥ���ں���ڼ�����������������ֹ������������\n"
	);
   	set("unit","��");
   	set("weight", 10);
   	set("value",({ 100, "silver" }) );
//	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int move(mixed ob)
{
	if ( ob && living(ob))
		call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

int eat_food(string arg)
{
		if( !arg || arg != "dumpling" ) return 0;
		write( "�����̻����ĳ������̰���..��? �����и���ֵ�ë?\n" );
		tell_room( environment(this_player()),
		this_player()->query("c_name")+"�ɿ�سԵ���һ�̰��ӣ�Ȼ��\n"     
	        "һ�����ɵĴ��������һ��ë...\n" , this_player());
		this_player()->receive_healing( 8+random(2) );
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	if ( !owner ) { 
//	what->set ("value", ({ 1, "silver" }));
//	what->set_short("���˵ĳ����");
//	what->set_long("������˱�ɻ�ɫ�����ܳ��ˡ�\n");
//	what->set("is_fresh",0);
	if( living(owner) )
	tell_object(owner,"���ŵ���İ��ӷ���һ����˵�ζ��������ö������ȽϺ�!!\n"
	"�㶪��һ�����˵������\n");
	}
	remove();
}

