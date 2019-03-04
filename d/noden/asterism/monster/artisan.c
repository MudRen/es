#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(15);
	set_name( "Artisan Leo", "�����˹�����ŷ" );
	add("id",({"artisan","halfling","leo"}) );
	set_short( "�����˹�����ŷ" );
	set_long(
		"һ����������(fix)ħ����Ʒ�İ��˹�����\n"
	);
	set( "gender", "male" );
	set( "race", "halfling" );
	set( "alignment", 600 );
	set( "time_to_heal", 8 );
        set("max_hp",500);
        set("hit_points",500);
	set_natural_armor( 80, 39 );
	set_natural_weapon( 60 , 30 , 48 );
	set_perm_stat( "str", 27 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "con", 35 ); 
        set_perm_stat( "kar", 30 );
        set("special_defense",(["all":40,"none":0]));
        set("aim_difficulty",(["critical":30,"weakest":30,
                               "vascular":30,"ganglion":30 ])) ;

        set_skill("dodge",65)    ;
        set_skill("unarmed",100) ;
	set( "wealth/gold", 100 );
	set( "inquiry" , ([ "fix":"@@fixing",]) ) ;

}

void init()
{
  add_action("fix_item","fix") ;
}

void fixing(object who)
{
  tell_object(who,"��ŷ˵:�ǵģ�ֻҪ�Ǳ��ǵĲ�Ʒ����Ӧ�û��ޡ�\n") ;
}

int fix_item(string s)
{
     if( !s || s!="wand" )
        return notify_fail("��ŷ˵: ����ʲ�ᶫ�� ? �������� ??\n" );
     write("�����Ҫ���ٸ����,Ҫ�޾ͰѶ������Ұ� !!\n" );
     return 1;
}

int accept_item(object me,object item)
{
	string name ;
	name = (string)item->query("name");
	if ( name != "Wand of Ultimate" ) {
		tell_object(me,"��ŷҡҡͷ : �Ҳ��������ֶ�����\n");
		command("give "+name+" to "+(string)me->query("name"));
		return 1;
	} else
	if (!item->query("damaged"))	{
		tell_object(me,"��ŷҡҡͷ : ����Ȳ�û�л�����ŷ������֮�Ȼ����㡣\n");
		item->move(me);
		return 1;
	} else
	if ((int)me->query("wealth/gold")< 300)	{
		tell_object(me,"��ŷҡҡͷ : ���Ǯ��������ŷ������֮�Ȼ����㡣\n");
		item->move(me);
		return 1;
	} else {
	tell_object(me,"��ŷת��ͷ����ʼŬ������ !!\n");
	call_out("do_fix",4,me,item);
	return 1;
	}
}

int do_fix(object me,object wand)
{         
          me->add("wealth/gold",-300) ;                
          wand->set("short","����֮��") ;
          wand->set("weapon_class",40) ;
          wand->set("damaged",0) ;
          wand->set("min_damage",24);
          wand->set("max_damage",37);             
          write("��ŷ˵: �޺��ˣ�����õ���������Ū���ˡ�\n" );
		  command("give wand to "+(string)me->query("name"));
          return 1 ;
}


