#include </u/t/takeda/takeda.h>
inherit ARMOR;

void init()
{
object holder;
string name;

 holder = environment(this_object());
 name=(string)holder->query("name");
 if (name!="mercury") {
 this_object()->remove();
                    }


add_action("cure","makeup");
}

int cure(string arg)
{
	object dest,owner;
	
	owner = environment();
	if( !arg || arg=="" )
		return notify_fail("Usage: makeup <someone>\n");
	if( !dest= present(arg, environment(this_player()) ) )
		return notify_fail("That is not here!\n");
	if( !living(dest) )
		return notify_fail("Only living things can be healed!\n");
	tell_room(environment(this_player()),"\n\n " +owner->query("c_cap_name")+"��������������Ϳ��Ϳȥ��\n\n");
	tell_room(environment(this_player()),"\n ��ʱ��ע�⵽���ܵĿռ俪ʼ�ۼ��˴�����ˮ���ⲻ�Ǵ�˵��ˮ�ǵ����������𣿣� \n");
	tell_room(environment(this_player()),"\n ͻȻ�䣬ˮ��֮��ɢ������ˮ���Χ��"+dest->query("c_cap_name")+".....\n");
        tell_room(environment(this_player()),"\n �����е�ˮ����������ʧ֮�ᣬ"+dest->query("c_cap_name")+"�������Ѿ��ָ������״����\n");
	dest->set("hit_points", (int)dest->query("max_hp"));
	dest->set("spell_points", (int)dest->query("max_sp"));
	dest->set("talk_points", (int)dest->query("max_tp"));
	dest->set("force_points", (int)dest->query("max_fp"));	
	dest->set("endurance_points", (int)dest->query("max_ep"));
	write("Ok.\n");
	return 1;
}


void create()
{
        set_name( "mercury pen", "ˮ��֮��" );
        add( "id", ({ "pen" }) );
        set_short( "mercury pen", "ˮ��֮��" );
        set_long(
        "This a pen of mercury!\n",
	"����һֻˮ��֮��ӵ�������˿ڵ�������\n"
	);
        set("no_sell",1);
        set( "type", "shield" );
        set( "prevent_drop",1);
        set( "armor_class", 80 );
        set( "defense_bonus",20 );
        set( "extra_stat",(["con":1970]));
        set( "weight", 1 );
}
int query_auto_load() { return 1; }
