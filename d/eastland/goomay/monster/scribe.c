#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level( 9 );
        set_name( "Hsin the scribe", "��ʦү" );
        add( "id", ({ "scribe","hsin" }) );
        set_short( "��ʦү" );
        set_long(
@LONG
��ʦү������Ʋϡϡ�����С���ӣ�����һ����������������һλ˽����ʦ
�����������ŵ�һ����������ʮ�����У���˱�������̫ү(magistrate)
���ã�����һ���ú�������ֻҪ����ʲ��ɱ�˷Ż�Ĵ�������������ܻ�
�л��ᷭ������һ��ֵ���и����ˡ�
LONG
        );
        set( "gender", "male" );
	set("race","elf");
	set( "alignment",600);
        set_natural_armor( 40, 10 );
        set_natural_weapon( 13, 9, 16 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "dodge", 100 );
        set_skill( "parry", 100 );
        set_skill( "target",80);
        set_skill( "concentrate",80);
        set_skill( "elemental",80);

        set( "tactic_func", "my_tactic" );
        set( "spells/sleet",2);
        set("spell_power",0);

	set( "defense_type","parry");
        set( "hit_points", 250 );
        set( "max_hp", 250 );
	set( "wealth/gold",10);
		set("spell_levels/elemental",15);
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
                "statue"  : "@@ask_statue",
		"magistrate" : "@@ask_magistrate",
        ]) );

}
int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 60 )
                set( "spell_points",query("max_mp"));
        command("cast sleet at "+(string)victim->query("name"));
}

int ask_magistrate()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")> 2)
        {
        tell_object(me,
        "��ʦү������лл��������̫үһ�����������Ѿ��ö��� !!��\n");
        return 1;
	}
        else
        {
        tell_object(me,@C_MAGI
��ʦү��������̫ү����æ��û��ʱ������ˣ����û�й����ϵ���Ҫ������
�������ģ����¾�����Ϊ��ת��� !!��
C_MAGI
        );
                return 1;
}
}
int ask_statue()
{
        object me ;
        me=this_player();
        if ( (int)me->query_quest_level("Goddess_statue")>2)
        {
	tell_object(me,
	"��ʦү���������������Ѿ��һ������𣿲�������лл����̫үһ�� !!��\n");
	return 1;
	}
        else
        {
        tell_object(me,@C_STATUE
��ʦү�������� !! ����� !! ˵������ ���� ���������Ѿ�ץ���Ǹ���������
�������ƻ����ԣ���Ҳ���ϰ����ｻ�������β�ͷ���˼���������װ��װ��ģ���
��̫үֻ�ð�����Ѻ���󣬲�������Ȼ�����䲻������ͬһ������͵͵�ڵص�����
��������������ȫ��׷�����ǡ������� !! �Ǹ�������� .. ��Ҫ�ٵ�һ��ʱ��ඡ�
C_STATUE
        );
                return 1;
}
}
