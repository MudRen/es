#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

// ��ֻ���ǰ����Ʒ�� ..... ��� QC ʱ�ع�����������Ȱ��ع��ص�

void create ()
{
        object obj1,obj2,obj3,obj4;
        ::create();
        set_level(19);
        set_name("Hawkman Chief Flamen","�������ܼ�˾");
        add("id",({"","hawkman","flamen"}) );
        set_short("�������ܼ�˾");
        set_long(@C_LONG
�㿴��һ���׷��ԲԵ����ˣ����ϵ���ë���Ѿ������ˣ�������Ȼ�����
���վ�ڴ�����������һ���᳤������ġ�������������������(door)���
��̳�������������������������ת��ͷ����Ͱ���Ц��һ�¡�
C_LONG
        );
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "λ" );
        set("inquiry",([
              "square":"@@ask_square",
                "door":"@@ask_door",
	"destroy":"@@ask_destroy",
                        ]) );
        set( "alignment",-800);
        set_perm_stat( "dex", 15 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 27 );
        set_skill( "dodge" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 1000 );
        set ("hit_points", 1000 );
        set_natural_weapon( 53 , 28 , 45 );
        set_natural_armor( 10 , 20 );
        set( "aim_difficulty",
                ([ "critical":40,"weakest":70,"ganglion":30,"vascular":50 ]) );
        set ("special_defense",([
                "monk": 20, "scholar": 20, "evil": 80,
                "divine": -20, "all": 30]) );
        set( "tactic_func","my_tactic");
        equip_armor(ARMOR"magerobe.c");
        equip_armor(ARMOR"star_arm.c");
        obj1 = new(OBJ"square_obj");
        obj2 = new(OBJ"square_obj");
        obj3 = new(OBJ"square_obj");
        obj4 = new(OBJ"square_obj");
        obj1->move(this_object() );
        obj2->move(this_object() );
        obj3->move(this_object() );
        obj4->move(this_object() );

}


int ask_door()
{
        tell_object(this_player(),@LONG
�������ܼ�˾�������е�Ц��һЦ��˵��
    ���������Ŷ�����ͨ���䶷��(square)��������������а���ȴ�в�һ
����·��������һ·�����������ߵ�·��ָ�������������....������а��
���˰��������ڰ���·�߰ɡ�
LONG
        );

        return 1;
}

int ask_square()
{
        tell_object(this_player(),@LONG
�ܼ�ʦ˵��
    �䶷��������������ı���ĵط��������������һЩа��Ĺ����̾���
���棬������˿Ͻ�ȥ����������(destroy)��Щ����Ļ����Ǹ��ж�á�
LONG
        );
        return 1;
}

int ask_destroy()
{
        if (!present("amulet",this_object() ))
        {
                tell_object(this_player(),@LONG
���˼�ʦ˵��:
��....�����Ѿ�̫���˸���˵Ҫ��æ�ˣ�������Ϊ������������ʥ�Ľ����֧
�ŵģ�û�취��̫���˽�ȥ���㻹�ǵ��´ΰɡ�
LONG
                );
                return 1;
        }

        tell_object(this_player(),@LONG
���˼�ʦ˵��:
Ŷ����Ը�����������? ������������, ���Ե����䶷�����볡֤��
LONG
        );
        command("give amulet to "+(string)this_player()->query("name") );
        return 1;
}


int my_tactic()
{
        object victim,tape;
        string name;
        int dex,choice;
        if (!victim = query_attacker()) return 0;
        name =(string)victim->query("c_name");
        dex = victim->query_perm_stat("dex");
        if( !victim ) return 0;
        choice = random(4);
        switch(choice)
        {
                case 0 : return 0;
                         break;

                case 1 :
                if ( random(dex) > 15 ) return 0;
                if ( victim->query_temp("no_hearing") ) return 0;
                tell_room(environment(victim),"\n�ϼ�˾���˫�֣��ɿ����"+
                        name + "��˫������һ�¡�\n",victim);
                tell_object(victim,@C_LONG
�ϼ�˾���˫�֣������˫����������һ�£����ʱ�е�˫��һ���ʹ��
............
[�����ˡ�]
C_LONG
                );
                victim->set_temp("no_hearing",1);
                victim->receive_special_damage("none",30);
                victim->set_temp("block_message",1);
                return 1;
                break;

                case 2 :
                if ( random(dex) > 12 ) return 0;
                if ( victim->query_temp("no_sight") ) return 0;
                tell_room(environment(victim),
                        "\n�ϼ�˾����������һ�У���Ȼ������"
                        + "��ʳ�ж�ָ��"+ name + "��˫�۲�ȥ��ֻ��"+ name
                        + "ʹ���ڵ��Ϲ�����ȥ��\n",victim);

// ��������Ѿ����˾Ϳ���������� message .... ��֪�������̨� ....

                tell_object(victim,@LONG
�ϼ�˾����������һ�У���Ȼ���ַɿ�����������к���ʳ�ж�ָ����
���˫�ۡ���˫��һ���ʹ���������׶༪�١�
[ ��Ϲ�ˡ�]
LONG
                );
                victim->set_temp("no_sight",1);
                victim->receive_damage(15);
                victim->set("blind",1);
                return 1;
                break;

                case 3 :
                if ( victim->query_temp("no_sound") ) return 0;
                if ( random(dex) > 12 ) return 0;
                tell_room(environment(victim),
                        "\n�ϼ�˾����Ʈ��, ��Ȼһ����ȭֱ����"
                        + name + "�ĺ�����ֻ��" + name
                        +"��ɫ��䡣\n",victim);

                tell_object(victim,@LONG
�ϼ�˾һ����ȭ������ĺ�������ֻ�������ƺ�΢΢������ĺ�ͷһ�£�
�����ͷ�����һ���ֶ�����������~~~~~

[ �����ˡ�]
LONG

                );

                victim->receive_damage(30);
                victim->set_temp("no_sound",1);
                tape=new(OBJ"tape");
                tape->move(victim);
                return 1;
                break;

                }
        return 1;
}
