#include <mudlib.h>
inherit ARMOR;

nosave string c_org_name ;
nosave string org_name ;
nosave string *old_ids;
int query_sp_cost(object me);

void create()
{
	seteuid(getuid());
	set_name("mask","面具");
	set_short("面具");
	set( "long","@@query_long");
	set( "unit", "张" );
	set( "type","head");
	set( "armor_class",1);
	set( "defense_bonus",0);
	set( "material", "thief");
	set( "weight",5 );
	set( "value",({10,"silver"}));
	set( "no_sale", 1);
	set( "equip_func","wear_me");
	set( "unequip_func","unwear_me");
	set( "c_mask_name","面具");
	set( "mask_name","mask");
	set( "extra_ids",({}));
}

string query_long()
{
	if ( (string) this_object()->query("mask_name") != "mask" )
		return "这是一张" + (string) this_object()->query("c_mask_name") + "的面具，作得栩栩如生。\n";
	else
		return "这是一张面具。\n";
}


void wear_me()
{
	object me,mask,*inv;
	string new_title,tmp1,tmp2;
	int sp;

	me = this_player();
	mask = this_object();

	tell_room(environment(me),sprintf("%s拿起一张面具,开始在脸上搓揉, 不一会儿\功\夫, 他的样子全变了 !\n",me->query("c_name") ),me);
	write(sprintf("你拿起一张%s的面具, 开始化装..\n",(string) mask->query("c_mask_name") ));

	org_name = (string) me->query("name");
	c_org_name = (string) me->query("c_name");
	old_ids = (string *) me->query("id");

	//  记住原来的 id
	me->set("org_name",org_name);
	me->set("c_org_name",c_org_name);

	if ( (string) mask->query("c_mask_name") == "面具" || (string) mask->query("mask_name") == "mask" ) {
	} else {
		me->add( "id",mask->query("extra_ids") );
		me->set( "name",(string) mask->query("mask_name") );
		me->set( "c_name",(string) mask->query("c_mask_name") );
		me->set( "c_cap_name",(string) mask->query("c_mask_name") );
		me->set( "title",(string) mask->query("c_mask_name"));
		me->set( "make-up", 1);
		if ( (int) me->query("spell_points") < (sp = query_sp_cost(me)))
			me->set("spell_ponts",0) ;
		else
			me->add("spell_points",-sp);
	}
}

void unwear_me()
{
	object me,mask;
	string *ids;

	me = this_player();
	mask = this_object();
		me->set("id",old_ids );
		me->set( "name",org_name );
		me->set( "c_name",c_org_name );
		me->set( "c_cap_name",c_org_name );
		me->set( "title",me->query_title()) ;
		me->set( "make-up", 0);

}

/* need think here */
int stop_equip(object me)
{
	if ( (int) me->query_skill("trick") < 1 ) {
		tell_object(me,"你的易容术太糟了, 还是不要试的好, 免的弄坏面具\n");
		return 1;
	}
	if ( (int) me->query("spell_points") < query_sp_cost(me) ) {
		tell_object(me,"你的精神力太低了, 无法集中精神化装。\n");
		return 1;
	}
	return 0;
}
int query_sp_cost(object me)
{
	return (100 - (int)me->query_level()*5);
}

string unequip_c_verb(string type)
{
	return "小心翼翼的脱下";
}
