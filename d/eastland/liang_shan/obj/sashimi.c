#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#define FRESH_TIME 60

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("fish meat","�ƽ��λ��������");
	add( "id" , ({ "meat","fish" }) );
   set_short("�ƽ��λ��������");
   set_long( "��Ƥ��ҫ�������Ľ�ɫ��â���ڲ��ǰ�͸�������⣬��˵��\n"
             "�˼����ζ��\n" );
   	set("unit","��");
   	set("weight", 15);
	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
	if( !arg || arg != "fish" ) return 0;
	if( !query("is_fresh") ) {
        write("��Ե�һ�鸯���˵����⡣\n");
        tell_room( environment(this_player()),
           this_player()->query("c_name")+"�Ե�һ�鸯���˵����⡣\n"
                   , this_player()
		);
       (CONDITION_PREFIX + "sick")->apply_effect(this_player(),15,2,5);
	} else {
        write(
                "�����سԵ���һ��������, �������ζ�ڿ���������ɢ....:)\n" );
        tell_room( environment(this_player()),
                     this_player()->query("c_name")+"�Ե���һ�������⣬����"
                "���������...\n", this_player()
		);
           this_player()->receive_healing( 40+random(10) );
	}
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	what->set ("value", ({ 1, "silver" }));
   what->set_short( "����������" );
   what->set_long( "��������Ѿ������ˣ�����һ�����ŵ���ζ��\n" );
	what->set("is_fresh",0);
   if ( !owner ) { remove(); return ; }
   if( !living(owner) ) { remove() ; return; }
   write(
        "���ŵ�һ�ɳ�ζ����, ������ʲ�ᶫ�����˵����ӡ�\n"
	);
}
