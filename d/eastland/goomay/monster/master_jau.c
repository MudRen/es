
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(18);
        set_name( "Master Jau", "������" );
        add ("id",({ "jau","master"}));
        set_short( "������");
        set("unit","λ");
        set_long(
@C_LONG
��������һ������һ��Ĵ󺺣�������ǰ��\����ֻ�Ʊ�����������һֻ
�ơ�����ϸ�������ƣ�Ȼ���Լ��ȵ�����һ·�߹�������ֻ��������˫
���������㣬������������������һ�㶼������������
C_LONG
);
        set ("gender", "male");
        set ("race", "hawkman");
        set_natural_armor( 90, 20 );
        set_natural_weapon( -5, 5, 15 );
        set_perm_stat( "str", 30 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 30 );
        set_skill( "blunt", 100 );
        set_skill( "parry", 100 );
        set( "hit_points", 800 );
        set( "max_hp", 800 );
        set( "special_defense", ([ "all": 20 ]) );

        set( "wealth/gold", 100 );
        wield_weapon( Obj"thor_hammer" );
        equip_armor( Obj"thor_gloves" );

        set( "inquiry", ([
                "wine" : 
@WINE
���ƣ���Ҳ���ƣ��������Ⱳ�Ӻȱ��˸��ֺþ��Ҿƣ�����˵
���ϾƳ��ˣ�����ʲ���û�ȹ���������˵������˴Ӻ������һЩ�¾ƣ�
�����ʲ��ӵģ���˵�ҵĺ� !! �ٺ� !! ���Ӿ������� ...��
WINE
]) );

}

int accept_item(object me,object item)
{
        string name;
        object obj;
        int i;

	name = (string) item->query("name") ;
	if ( name !="vodka" ) {
	tell_object(me,
		"������ҡҡͷ����лл !! �����Ҳ���Ҫ�ⶫ�� !!��\n");
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

        i = this_player()->query_temp("give_wine");
        if ( i )
                this_player()->set_temp("give_wine",i+1);
        else
                this_player()->set_temp("give_wine",1);
        if (i != 2){
                command("drink vodka");
                tell_room( environment(), 
                "�������������������������Ц�����þ� !! �㻹����\n");
	}
        else {
        command("drink vodka");
        tell_room( environment(), 
        "����������ڵ���������������Ц�������� !! ��Ҳ���������Եĺþ� !!\n" );
        me->delete_temp("wine");
        obj=new(Obj"old_wine");
        obj->move(this_object());
        command("give wine to "+(string)me->query("name"));
        me->set_explore("eastland#13");
	}
	return 1;
}
