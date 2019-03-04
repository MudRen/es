#include <../goomay.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Shu the migastrate of goomay", "��̫ү" );
        add( "id", ({ "migastrate","shu" }) );
        set_short( "��̫ү" );
        set_long(
@LONG
���������εĹ�÷����̫ү��ʷҫǰ���ʷ��ֵ�����������е��۾����㲻��
��Щ�������ǲ������ֻ��ʶǮ����Ȼ��ˣ�������������Ԫ���ڵĺ�״Ԫ��
��Ȣ���Ķ�ʦ����̫ʦ��Ů������С�㣬���ǵ�ʱ�����˵���Ľ�������⼸
�����ٲ��ࡢ���Ʋ��٣�ʮ��Ĳ��˺�ͨ��
LONG
        );
        set( "gender", "male" );
		set("race","elf");
        set_natural_armor( 40, 10 );
        set_natural_weapon( 20, 9, 22 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set("tactic_func","kill_me");
        set( "hit_points", 200 );
        set( "max_hp", 200 );
		set( "wealth/gold",30);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
        ]) );

}
void disappear()
{
	tell_room(environment(this_object()),"��̫ү�����ﵽ�����ˡ�\n",this_object());
	this_object()->remove();
}
int kill_me()
{
    object ob1,ob2,victim;
    if ( query("killed") ) return 1;
    victim = this_object()->query_attacker();
    tell_room( environment(this_object()),
   		"վ��һ�ߵĲ���е��������Ҷ�̫ү����ò !! �ֵ��� !! �������֪����ļһ￳�ɰ˿� !!����\n"
      ,this_object() );
                                                 
 	ob1 = new(Mob"cop" ); 
 	ob1 ->move_player( environment(this_object()), "SNEAK" ); 
 	ob2 = new(Mob"cop");
    ob2 ->move_player(environment(this_object()), "SNEAK" );
	ob1 -> kill_ob(victim);
	ob2 -> kill_ob(victim);
	this_object()->set("killed",1);
	call_out("disappear",2);
	return 1;  
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue") > 2 )
        {
	tell_object(me,
	"��̫ү���������������Ѿ��һ������𣿲�������лл������һ�� !!��\n"
		);
	return 1;
	}
        else
        {
	if (this_player()->query_temp("meet_jor"))
	{	
        tell_object(me,@C_STATUE
��̫ү��һ�ֺ��˷ܵ��۹⿴����������ٺ� !! �������ǡ��Ļ�Ҳ�������ղ�
���˰� !! ��Ҫ�־�Ҫ��������һ�������Դ��� ... ������ !!! ������Ц������
�߹��������Ͻ���ð��һ����Ļ𻨣���Ȼ������¡��һ�����������Ϊһֻ����
ð������Ĺ��
C_STATUE
        );
        clone_object( Mob"fire_monster" )->move_player(environment(this_object()), "SNEAK");
        me->remove();
                return 1;
	}
	else
	{
        tell_object(me,@C_STATUE
��̫ү��һ�ֺܳٻ������˵���������� !! �������ǡ����׼����¹��Ѿ�ͨ��
������ȫ��׷���ˣ����˴���Ѳ�أ���������������С��֮�£�������˲���
�һ���С��һ�������참�Ա��������
C_STATUE
        );
                return 1;
	}
}
}
