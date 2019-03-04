
#include "../goomay.h"

inherit Army;
int key =0;
void create ()
{
        ::create();
        set_name( "Captain of Policeman", "�η�ӥ" );
        add ("id",({ "captain","policeman","cop"}));
        set_short( "�η�ӥ");
		set("level",13);
        set("unit","��");
        set_long(
@C_LONG
�㿴��һ���ߴ�ǿ׳���ˣ�������ʹ�Լ��ʮ���꣬�������ɾ�������
ɫ�������Ǳ���Ĳ�ͷ���η�ӥ����������Ȥ�������ٷ��Ƽӿ���
�ˣ�����һ����Ϊֻ�����̲����ư����ˡ�
C_LONG
);
        set ("gender", "male");
        set ("race", "orc");
        set_natural_armor( 70, 25 );
        set_natural_weapon( 30, 15, 30 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_skill( "unarmed", 100 );
        set_skill( "parry", 100 );
        set("alt_corpse","NONE");
        set( "hit_points", 300 );
        set( "max_hp", 300 );
        set( "special_defense", ([ "all": 20 ]) );
        set( "inquiry", ([
		"key"  : "@@ask_key",
                "jail" : "@@ask_key",
        ]) );

}

int ask_key()
{
        object me ;
        me=this_player();
   if( (int)me->query_quest_level("Goddess_statue") < 2 ){
	if (key)
	{
	tell_object(me,
        "�η�ӥ������Ӣ�۸��� !! ���Ѿ���Կ�׸����ˡ���\n");
	return 1;
	}
	else
	{
        tell_object(me,
        "�η�ӥ������ԭ������ս���ֵ�Ӣ�� !! Կ���������\n");
	key=1;
	new(Obj"key1")->move(this_object());
	command("give key to "+this_player()->query("name"));
        return 1;
	}
	}
        else
        {
        tell_object(me, 
"�η�ӥ�����������ȥ !! ȥ !! ȥ !! û�������η�Կ����ʲ�᣿��Ҫ�����𣿡�\n"
			);
                return 1;
}
}

void die()
{
 tell_room( environment(this_object()),
@C_DIE

�η�ӥͻȻ������ı����У��������������ã������С�Ӹ���ץ������
���ͷһ����������ƭ�ˣ�������תͷ�������η�ӥ�Ѿ��ܵĲ�����Ӱ�ˡ�

C_DIE
 ,this_object() );

	::die(1);                
}

void reset()
{
	key=0;
}
