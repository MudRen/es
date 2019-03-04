#include "hawk.h"

inherit ROOM;
int be_move;
void create()
{
        ::create();
        set_short("����");
        set_long(@LONG
������С·������ʯ����������ͺͺ��ʯ���ϡ������п���ɫ��ֵ�
��ʯ(rock)��أ�����Ը��������ҿ鿴�����ܲ���������߼��ϱߵ���
�ݴ��������������͵ľ��ڶ���(precipice) ��Զ�紵�������ɽᰣ�
������о����Ĳ�����ˬ������һ�ɲ�����������֪�Ķ�����ϸ΢����
�������������ϸ�Ļ������ܶ�û�з���������ټ��������ֿ��µ�
�ط�����������ߵĻ������ܻ�ʧ�����¡�
LONG
);

        set_outside("noden");
        set("c_item_desc",([
                "rock":"@@to_rock",
                "lever":"@@to_lever",
                "precipice":" ����׵��ͱ�, Ҫ��һ����С��ˤ��ȥ, ���С����û�ˡ�\n"
                                ]) );

        set("search_desc",([
                "rock":"@@to_search_rock",
                        ]) );
        set("exits",([
                "southwest" : HAWK"room1-1"
                        ]) );
        reset();
}

void init()
{
        add_action("to_move","move");
        add_action("to_pull","pull");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" )
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

int to_pull(string str)
{
        if ((!str) ||(str!="lever") || (be_move<2) )
        return notify_fail("Ҫ����ؼ�ȥ����!\n");
        tell_object(this_player(),
                "�����������°��..."+
                "��Ȼ����µ�ʯ��������......\n\n\n ����ॣ�����\n"+
                "�������˱�ʯ�嵯��һ���µĵط�.....\n" );
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name") +
                "��ʯ�嵯������ȥ��!\n",this_player());
        this_player()->move_player(HAWK"room1-3","SNEAK");
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "��ֻ����ƵĴ������!\n",this_player());
        return 1;
}

int to_move(string str)
{
        if ((!str) || (str !="rock" )) return notify_fail("��Ҫ�ƶ�ʲ��ѽ?\n");
        if (be_move==0)
        {
                tell_object(this_player(),
                        "��ʹ�����̵����������Ʋ���ʯ�顣\n");
                tell_room(environment(this_player()),
                        "�㿴��"+(string)this_player()->query("c_name")+
                        "ʹ�����̵��������ƶ�ʯͷ��"+
                        "����ʯ���Ʒ粻����\n",this_player());
        }
        else
        {
                be_move=2;
                tell_object(this_player(),
                        "��ǳ��������Ƽ�ʯͷ....\n\n\n"+
                        "��춰�ʯͷ�Ὺ�˼�����֮��....ʯͷ�����ƺ�����ʲ������...\n"+
                        "�����ֵ�ʯͷ������ѽ�ڵ�, �������и�����(lever)! \n");
                tell_room(environment(this_player()),
                        "�㿴��"+(string)this_player()->query("c_name")+
                        "�����İ�ʯ���ƿ���һ����롣\n",this_player() );}
        return 1;
}

string to_search_rock()
{
        if ((be_move==0) || (be_move==1))
        {
                be_move=1;
                return "������ϸ�ļ�����ʯͷʱ, ϸ�ĵ��㷢��ʯ���е��ɶ���\n"
                "Ҳ����Գ���ȥ�ƶ�(move)������\n";
        }
        else
        {
        return "һ�����ƶ�����ʯͷ, �����и�����(lever)\n" ;
        }
}

string to_rock()
{
        if ( (be_move==0)||(be_move==1) )
                return "һ����ɫ����ľ�ʯ,��֪Ϊ�λ���������\n";
                return  "һ�鱻�ƶ����ľ�ʯ,ʯͷ������֧����(lever)��\n";
}

string to_lever()
{
        if ((be_move<2) ) return "����û������������\n";
        return "������˿�����������(pull), ��֪������ʲ������\n";
}
void reset()
{
        ::reset();
        be_move=0;
}
