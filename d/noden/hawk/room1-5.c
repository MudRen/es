//room1-5.c
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("ʯ��С��");
        set_light(1);
        set_long( @LONG_DESCRIPTION
�ߵ���ߣ�ͻȻ�㷢�ֵ������Ѿ�������ʯ�壬���������ʶ��ˣ�����
��������ҰҲԽ��Խ�á������㻹�Ǹ㲻��ո�����������Щ��ֵ�������
�����ﴫ��������Ҫ����ǰ�߶�·����Ū���װɡ�
    С������ï�ܵ�ɭ��(forest)�����һ����ɭ�����еķ��㣬�����
���Ŀ�������
LONG_DESCRIPTION
        );
        set( "exits", ([
                "south" : HAWK"room1-6",
                "northwest" : HAWK"room1-4",
                     ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "skull":"@@to_skull",
                "ball":"@@to_ball"
                ]) );
        set("search_desc",([
                "forest":"@@to_search_forest",
                "skull":"@@to_search_skull"
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_move","move");
        add_action("to_touch","touch");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="northwest" )
                return 0;
        write("��! ����....\n\n");
        tell_room(environment(this_player()),
                "�㿴������ʧ����!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "�Ӹ��ʵľ�����ˤ����!\n"+
                "��Ȼû��! ��������!\n",this_player());
        return 1;
}

string to_skull()
{
        if (moves == 0) return "����û������������\n";
        return "һ�����ɫ������ͷ, ��������Ѿ��൱��Զ�ˡ�\n";
}

string to_ball()
{
        if (moves < 2) return "����û������������\n";
        return "һ�÷������ع�â��ˮ����, ���ϵ�������ȥ����(touch)����\n";
}

string to_search_skull()
{
        if (moves == 0)
        {
        return "ɶ..? ɶ..? ��Ҫ��ɶ...?\n";
        }
        else if (moves == 1)
        {
        moves = 2;
        return "������ͷ��������е㶫��,���������Ҫ���ƿ�(move)"+
               "��, ���ܿ��ø���ϸ��\n";
        }
        else if (moves > 1)
        {
        return "�ٶ���Ҳ��û���õ�, ʡ�������ɡ�\n";
        }
}

string to_search_forest()
{
        if ((moves == 0) || (moves == 1))
        {
        moves = 1;
        return "�ۣ�����ɭ�ֵ���ҵ�һ������ͷ(skull)\n" ;
        }
        else
        {
        return "����������, ����ûɶ�·���\n";
        }
}

int to_touch(string s)
{
        if ((!s) || (s!="ball") || (moves != 3 ))
                return notify_fail("����������С���´α�·��С�����ɧ���\n");
        tell_object(this_player(),
                "����ѽ������ѽ�������˰��죬Ҳû����ɶ�£�������"+
                "һ����ƭ�˵ĸо���\n");
        this_player()->set_temp("touch_ball",1);
        return 1;
}

string to_forest()
{
        return "һƬï�ܵ�ɭ��, ����֪����, �����Ǿ�����һ�ɹ������������
����Ƭɭ�֡��㿿��ɭ��, ����ԼԼ���ܵ�һ��Ѫ�ȵ�ζ��, �ܶ���
����Ҳ�в��ٱ���ɱ�������µĺۼ�, ��������һ�����й�һ����
ս��\n";

}

int to_move(string str)
{
        if ((!str) || (str!="skull") || (moves == 0))
        {
                tell_object(this_player(),
                        "....�Ҷ��Ҷ������ɽ��ȥม�\n");
                return 1;
        }

        if (moves == 1)
        {
                tell_object(this_player(),
                        "��....�������룬���Ǿ�����Ҫ�Ҷ��������ͷ�Ƚ��׵���\n");
                return 1;
        }

        if (moves == 2)
        {
                moves = 3;
                tell_object(this_player(),
                        "������İ�����ͷ�ƿ�..��..�㿴��һ����"+
                        "˸�����ع�â��ˮ����(ball)\n");
                tell_room(environment(this_player()),
                        "�㿴��"+(string)this_player()->query("c_name")+
                        "�ҵ���һ��ˮ����!\n",this_player());

                return 1;
        }

        if (moves == 3)
        {
        tell_object(this_player(),"����Բ��������ˡ�\n");
        }
        return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}
