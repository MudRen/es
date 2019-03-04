#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#define FRESH_TIME 180

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
   set_name( "lamb", "Ѭ����" );
   add( "id" , ({ "leg" } ) );
   set_short( "Ѭ����" );
   set_long(
        "һֻɫ������, ��������Ŀ�����, ���˲���ʳָ�󶯡�\n"
	);
   set( "unit", "ֻ" );
   set( "weight", 25 );
   set( "value", ({ 300, "silver" }) );
	call_out("not_fresh", FRESH_TIME, this_object() );
	set("is_fresh",1);
}

int eat_food(string arg)
{
   if( !arg || (arg != "leg" && arg != "lamb" ) ) return 0;
	if( !query("is_fresh") ) {
        write( "�����һֻ���˵�Ѭ���ȡ�\n" );
        tell_room( environment(this_player()),
                 this_player()->query("c_name")+"����һֻ���˵�Ѭ���ȡ�\n"
                 , this_player() );
       (CONDITION_PREFIX + "sick")->apply_effect( this_player(), 15, 2 );
	} else {
        write(
                "�����سԵ���һֻѬ���ȡ�Ȼ�������ǵ����ա�\n" );
        tell_room( environment(this_player()),
             this_player()->query("c_name")+"�Ե���һֻѬ����, ���ƺ������ٳ�һֻ.\n", this_player() );
        this_player()->receive_healing( 25+random(5) );
	}
	remove();
	return 1;
}

void not_fresh(object what)
{
	object owner;
	owner = environment(what);
	what->set ("value", ({ 1, "silver" }));
   what->set_short( "���˵�Ѭ����" );
   what->set_long( "����һ�����˵�Ѭ����, ���ܳ��ˡ�\n" );
	what->set("is_fresh",0);
   if ( !owner ) { remove(); return ; }
   if( !living(owner) ) { remove() ; return; }
   write(
        "���ŵ�һ�ɳ�ζ����, ������ʲ�ᶫ�����˵����ӡ�\n"
	);
}
