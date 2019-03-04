#include <mudlib.h>
#define MIX "/d/healer/mix"
#define MESS_OB "/d/healer/potion/mess"

inherit CONTAINER;

void create()
{
	::create();
	seteuid(getuid());
	set_name( "herb bowl", "ҩ��" );
	add( "id", ({ "bowl" }) );
	set_short( "an herb bowl", "ҩ��" );
	set_c_open_long(
		"����һ����ҽ��������ĥ��ҩ��ҩ��������Ҫ��ĥ��ҩ�ķŽ�ҩ����Ȼ��\n"
		"�� mix ָ��ɡ�\n" );
	set( "weight", 10 );
	set( "value", ({ 100, "silver" }) );
        set( "max_load", 80 ) ;
	set( "weight_apply", 100 );
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
	object *inv;
	string potion;
	int i,number;
	int weight;
	object the_potion;

	if( arg && !id(arg) ) return 0;
	if( !environment() || environment()!=this_player() ) return 0;
	inv = all_inventory();
	if( !sizeof(inv) ) return notify_fail( "���ҩ����ʲ��Ҳû��....��\n");
	potion=MIX->mix(this_object());
	weight=query("weight");
	for(i=0; i<sizeof(inv); i++) {
	        weight = weight - (int)(inv[i]->query("weight") );
	        this_player()->add("load",- (int)(inv[i]->query("weight") ) );
		inv[i]->remove();
	}	
	if( potion ) {
	     number=MIX->potion_amount();
	     for (i=0; i < number; i ++) {
	        the_potion = new(potion);
	        weight = weight + the_potion->query("weight");
	        this_player()->add("load",the_potion->query("weight") );
		the_potion->move(this_object());
	     }
		write( "�㽫ҩ�����ҩ�Ļ��ĥ�飬���" + the_potion->query("c_name") + "��\n"
	 	     );
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "��ҩ�����ҩ�Ļ��ĥ�顣\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	} else {
//		the_potion = new(MESS_OB);
//		the_potion->move(this_object());
//	        weight = weight + the_potion->query("weight");
//		this_player()->add("load",the_potion->query("weight"));
		write("�㽫ҩ�����ҩ�Ļ��ĥ��......������һ�����ࡣ\n" );
		write("��̾��һ����, ���ְ�ҩ��������������\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name") + "��ҩ�����ҩ�Ļ��ĥ�顣\n" ,
			this_player() );
		set("weight",weight);	
		return 1;
	}
}
