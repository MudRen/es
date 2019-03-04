// The file of based medication object, creatd by Annihilator.
// Updated by Kyoko, for inherit by potion, pill & herb.
// 3 functions: now as void eat(), void frink() & int apply().
// add a check to apply(), let herb can check some by itself.

#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
	set("reaction", 1);
}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_drink", "drink");
	add_action("do_apply", "apply");
}

int do_eat(string arg)
{
	int med;
	
	if( !query("can_eat") ) return 0;
	if( !id(arg) ) return 0;
	if( environment() && environment() != this_player() ) return 0;
	write(sprintf("�����һ%s%s��\n",query("unit"),query("c_name")));

	tell_room( environment(this_player()), 
		sprintf("%s����һ%s%s��\n",this_player()->query("c_name"),query("unit"),query("c_name")),
		this_player() );
	if( med = (int)query("medication") )
		this_player()->add("medication_resistance", med);
	this_object()->eat(this_player());
	this_object()->check_body(this_player());
	remove();
	return 1;
}

int do_drink(string arg)
{
	int med;
	
	if( !query("can_drink") ) return 0;
	if( !id(arg) ) return 0;
	if( environment() && environment()!=this_player() ) return 0;
	write(sprintf("�����һ%s%s��\n",query("unit"),query("c_name")));

	tell_room( environment(this_player()), 
		sprintf("%s����һ%s%s��\n",this_player()->query("c_name"),query("unit"),query("c_name")),
		this_player() );
	if( med = (int)query("medication") )
		this_player()->add("medication_resistance", med);
	this_object()->drink(this_player());
	this_object()->check_body(this_player());
	remove();
	return 1;
}

int do_apply(string arg)
{
	string str, dest;
	object act_ob, me;
	
	if( !query("can_apply") ) return 0;
	
	me = this_player();

	if( !arg || arg=="" ) return notify_fail( 
		"ָ���ʽ: apply <ҩƷ> [at <ĳ��>]\n");

	if( sscanf(arg, "%s at %s", str, dest) != 2 ) str = arg;
	if( !id(str) ) return 0;
	if( environment() && environment() != me ) return 0;
	if( !dest ) act_ob = me;
	else if( !act_ob = present(dest, environment(me)) )
		return notify_fail( 
			"��Ҫ��˭���˿ڷ�ҩ��\n");

	// modify by Kyoko, for making a system about all medicine.
	if( !this_object()->apply(me, act_ob) ) return 0;

	if( act_ob == me ) {
		write(sprintf("�㽫%s�����˿��ϡ�\n",query("c_name")));
		tell_room( environment(me), 
			sprintf("%s��һЩ%s�����Լ����˿��ϡ�\n",me->query("c_name"),query("c_name")), me);
	} else {
		write(sprintf("�㽫%s����%s���˿��ϡ�\n",query("c_name"),act_ob->query("c_name")));

		tell_object( act_ob,
			sprintf("%s��%s��������˿��ϡ�\n",me->query("c_name"),query("c_name")));
		tell_room( environment(me), 
			sprintf("%s��%s���˿ڷ���%s��\n",me->query("c_name"),act_ob->query("c_name"),query("c_name")),
			  ({ me, act_ob }));
	}
	remove();
	return 1;	
}

void check_body(object me)
{
	int med, max, tmp, dam, dur;

	if( !query("reaction") ) return;

	med = (int)me->query("medication_resistance");
	max = (int)me->query("critical_med_res");
	if( (tmp=(int)query("reaction_critical")) > 0 )
		max = max * tmp / 100;

	// run the reaction?
	if( med > max )
		if( !this_object()->reaction(me) ) {
			dam = 1 + ( med - max ) / 100;
			dur = 1 + ( med - max ) / 20;
			SICK->apply_effect(me, 10, dur, dam);
		}
}
