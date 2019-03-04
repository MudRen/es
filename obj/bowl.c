#include <mudlib.h>
#define MIXD "/d/healer/mixd"
#define MESS_OB "/d/healer/mess"

inherit CONTAINER;

void create()
{
	::create();
	seteuid(getuid());
	set_c_open_long(
		"����һ����ҽ��������ĥ��ҩ��ҩ��������Ҫ��ĥ��ҩ�ķŽ�ҩ����Ȼ��\n"
		"�� mix ָ��ɡ�\n" );
#include <compress_obj.h>
	set_name( "herb bowl", "ҩ��" );
	add( "id", ({ "bowl" }) );
	set_short( "an herb bowl", "ҩ��" );

	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
	set( "max_load", 40 );
	set( "weight_apply", 50 );
	set( "prevent_insert", 1 );
	set( "prevent_put_money", 1 );
}

void init()
{
	::init();
	add_action( "do_mix", "mix" );
}

int do_mix(string arg)
{
	object *inv, potion;
	int i;

	if( arg && !id(arg) ) return 0;
	if( !environment() || environment()!=this_player() ) return 0;
	inv = all_inventory();
	if( !sizeof(inv) ) return notify_fail( can_read_chinese()?
		"���ҩ����ʲ��Ҳû��....��\n": "Your herb bowl contains nothing.\n" );
	potion=MIXD->mix(this_object());
	for(i=0; i<sizeof(inv); i++)
		inv[i]->remove();
	if( potion ) {
		potion->move(this_object());
		write( 
			"�㽫ҩ�����ҩ�Ļ��ĥ�飬���" + potion->query("c_name") + "��\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "��ҩ�����ҩ�Ļ��ĥ�顣\n" ,
			this_player() );
		return 1;
	} else {
		potion = new(MESS_OB);
		potion->move(this_object());
		write( 
			"�㽫ҩ�����ҩ�Ļ��ĥ��......������һ�����ࡣ\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "��ҩ�����ҩ�Ļ��ĥ�顣\n",
			this_player() );
		return 1;
	}
}
