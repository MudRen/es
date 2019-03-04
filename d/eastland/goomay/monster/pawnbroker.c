
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Pawnbroker", "������" );
        add ("id",({ "liu"}));
        set_short( "������");
        set("unit","λ");
        set_long(
@C_LONG
    ����һ������һֻ������Ƭ���ϳ��һ�����쳤�ۼ��Ϲ�ƤСñ��
һ���;������Ǹ�ʮ�ֽ������ˣ������ϣ������Ǿ���������������
����֮һ����ҵ���쵱���ĵ�һ�������֣������ר����Ǯ�����ؽ���
Ƹ���������ڹ�÷��ĸ����кŵġ�����\�������������й���̵��
���֡�
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set( "alignment",300);
        set_natural_armor( 50, 20 );
        set_natural_weapon( -10, 1, 3 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "kar", 12 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "blunt", 80 );
        set_skill( "parry", 60 );
        set( "hit_points", 280 );
        set( "max_hp", 280 );
        set( "special_defense", ([ "all": 20 ]) );
	set("wealth/gold",20);
        wield_weapon( Obj"abacus" );
        equip_armor( Obj"long_garb" );
        equip_armor( Obj"round_cap" );
        equip_armor( Obj"emerald_ring" );
        set( "inquiry", ([
		"statue"  : "@@ask_statue",
        ]) );

}

int ask_statue()
{
        object me ;
        me=this_player();
       if ((int)this_player()->query_quest_level("Goddess_statue")>2 ) {
                tell_object(me,
                "���ƹ�Ц�������������Ѿ��һ����ˣ���л���İ�æ !!��\n");
                return 1;
	}
        else
        {
	tell_object(me,@C_STATUE
���ƹ�̾��������������������̵ľ������磬��˵������ǿ���������һ��
Ϊ�ý̵����֮���������ǰ�һؾ��ǰ��£��ص��������Ǿ�Ȼ��������
һ������ɽ�󣬽���������Ͼ�����ҹ���ⷿ������ֻ͵�������������ŵ�
��������������Ȼ�������ᣬ����̵��˷׷��ҵ���ͷ�ϣ���в���ա�ҪɱҪ
�еģ������������а취��������˵������ץ�ˣ��ҸϽ���������ͨ�����Ҳ
û����������䣬����������ȻԽ���� ... �� ... ��Ǭ���������ˡ�
C_STATUE
	);
                return 1;
	}
}

int accept_item(object me,object item)
{
     if ( ((string) item->query("name") !="The statue of Goddess" &&
	 (string) item->query("name") !="broken symbol") ||
       (int)this_player()->query_quest_level("Goddess_statue")>2 ) {

     tell_object(me,
        "���ƹ������лл !! �������Ǹ���ʵ�������ˣ�����������Ķ����� ��\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

	if ( (string)item->query("name") == "broken symbol" ) {
     tell_object(me,@SYMBOL
���ƹ������ !! �ⶫ���������ƺ��ܲ�ƽ������β�����ֽ��˰������ޡ� 
����\�ָܻ��ɹ�Ҳ˵��������¬���˶���Ӧ������ݹ�\���� !!
SYMBOL
		 );
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
���ƹ������������ȥ�Ŀ���һ�飺���� .. ������������� !! лл�� !! ����
���� !! ���о��� !! �����߸����˵İ�Ů�������ܵ��ղ��������򿪿ⷿ��׼����
��Ӫҵ��

MISSION
);
	if (item->query("who_get_me") == this_player()->query("name")) {
	tell_object(me,
	"����������Ѱ������������� !! "+set_color("[ ��õ� 15000 �㾭�� ]","HIC")+"\n" );
	me->finish_quest("Goddess_statue",3);
        me->gain_experience(15000);
	}

        item->remove();

        return 1;
}
