#include <../goomay.h>
#include <stats.h>
#include <conditions.h>
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
        set_name( "daemonic snake", "��ħŮ" );
        add( "id", ({ "snake" }) );
        set_short( "��ħŮ" );
        set_long( @C_LONG
�㿴��һֻ��ͷ��������֣�����˫��ɢ����һ������Ĺ�â����ʹ
������ս���㣬���������һֻ���������ܴ�������ϵ����Ҳ
�̲�ס����ֱð���⡣
C_LONG
);
	set("killer",1);
	set("gender","female");
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 26 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "kar", 18 );
	set_skill( "parry", 100 );
	set( "alignment", -1500 );
	set( "natural_armor_class", 85 );
	set( "natural_defense_bonus", 35 );
	set( "natural_weapon_class1", 50 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 );
	set( "tactic_func", "my_tactic" );
}

void report( object attacker, object victim )
{
   seteuid(getuid());
   tell_object( victim,
    sprintf("( ��%s )\n","/adm/daemons/statsd"->status_string(victim))
   );
   return;
}

int my_tactic()
{
	object *victim,ob;
	int i,spec;

	if ( !victim = query_attackers() ) return 0 ;
        spec=random(100);
        if ( spec>50 ) return 0;

	if (spec <20)
	{
	tell_room( environment(this_object()), 
		"\n��ħŮ���һ̲��Һ����ʴ������� !!\n\n" ,
		this_object() );
	for( i=0; i<sizeof(victim); i++ )
	    {
		victim[i]->receive_special_damage( "acid", 30+random(10) );
		report(this_object(),victim[i]);
	    }
		return 1;
	}

	if ( spec<30 ) 
	{
        tell_room( environment(this_object()), 
		"\n��ħŮ���һ�Ŷ�����е�һ����ѣ !!\n\n" ,
                this_object() );
        for( i=0; i<sizeof(victim); i++ )
	(CONDITION_PREFIX + "simple_poison")->apply_effect( victim[i], 10, 7 );
		return 1;
	}

	if ( spec<50)
	{
	tell_room( environment(this_object()), 
		"\n��ħŮ�����Ƕ�������۾������㿴���������ͻȻһƬ�հ� !!\n\n" ,
		 this_object() );
	for( i=0; i<sizeof(victim); i++ )
		(CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5 );
	return 1;
	}

	return 0;
}

void die()
{
	object ob1;
	ob1 = new( Obj"statue" );
	ob1->set("who_get_me",query("last_attacker")->query("name"));
        ob1->move(this_object());
                ::die(1);
	tell_room( environment(this_object()), @FLEE
һ����ɫ������ͻȻ����ס��ħŮ�����������У�ȴ��Ů���񷢳�һƬʥ���
���������������ȥ����Ͻ�����ץס����ֻ����һ�ɼ�ǿ�������ӱ˶˴���
��Ȼ����ʧ����Ӱ���٣��㲻�����˿�ȥ������վ�������������Ѿ�ɢȥ�ˡ�

һ��̶���Ц����������Ķ���: �������� ... �޴����˰� ...���С�����ˣ�
����Ϊ�ڰ���������ʹ˷��� ... �һ������ ...

FLEE
		,this_object() );
}
