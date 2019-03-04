
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Darkgreen Mirror", "ī��ɫ�ļ�˼");
seteuid(getuid());
        add( "id", ({ "darkgreen mirror","mirror" }) );
        set_short( "ī��ɫ�ļ�˼" );
        set("long","����һ��ײ�ī��ɫ�ľ��ӣ��������������(see)�Լ�������ࡡ�\n");
        set( "weight", 3 );
        set( "unit", "��" );
}

void init()
{
        add_action("to_see","see");
}

int to_see(string str)
{
        string gen;
        gen = this_player()->query("gender");
        if (str != "mirror")
                return 0;
        if (gen == "male")
        {
                tell_object(this_player(),@LONG
�ۣ����ھ����￴��һ����˧�硣
�㲻�������Ц������������
.....................
LONG
                );
                call_out("m_next",5,this_player());
                return 1;
        }

        if (gen == "female")
        {
                tell_object(this_player(),@LONG
�ۡ����ھ��п���һ����������Ů��
�㲻����Ӱ��������������ɧ��Ū�ˡ�������
.....................
LONG
                );
                call_out("f_next",5,this_player() );
                return 1;
        }

        if (gen == "neuter")
        {
                tell_object(this_player(),@LONG
���Ӻ�Ȼ����ˡ�������

�����ǲ�ϲ�����....
LONG
                );
                this_object()->remove();
                return 1;
         }
}

void m_next()
{
        tell_object(this_player(),@LONG
��ͻȻ���־��������û�и���һ��Ц��������Ѫ���˫�۵����㡫����
���ܲ���������ţ�����һ����һ�ž����ˡ�
LONG
                );
        tell_room(environment(this_player()),
                "�㿴��"+(string)this_player()->query("c_name")+
                "��������ɵЦһ������Ȼ��ɫһ�䡫������\n",
                this_player() );
        call_out("die",3,this_player() );
}

void f_next()
{
        tell_object(this_player(),@LONG
��ͻȻ���־��е���û�к���һ�������������������������㡫����
���ܲ���������ţ������ڵ��ϡ�
LONG
                );
        tell_room(environment(this_player()),
                "�㿴��"+
                (string)this_player()->query("c_name")+
                "��������һ��ɧ��Ū�ˣ�ͻȻ���������ת��ͷ����Ȼ��������ڵ��ϡ�\n",
                this_player() );
        call_out("die",3,this_player());
}

int die()
{
        object wuchang;
        tell_object(this_player(),@C_LONG

�����ˡ�

��������ֵĸо�....��ƮƮ��....

�㿴�����Լ��������������ڵ���....��

�㿴��һ���ָ����ݵĺ�ɫ��Ӱ��������Ϣ���ߵ������� ....
���޳�˵��: ���Ѿ����ˣ����Ҹ���˾����ɡ�
���޳���һ���ִ����ص���������ͷ��һ�ף��ֱܴ�����������ǰ�ߡ�
��ֻ����ǰ���������һ���ι��������Ȼ�������һ��ʯ�� ....
C_LONG
        );
        tell_room(environment(this_player()),
                (string)this_player()->query("c_name")+
                "����һ�������ĲҽУ����ڵ��� ... ���ˡ�\n"+
                "�㿴��һ�ư�ɫ��Ӱ�Ӵ�"+
                (string)this_player()->query("c_name")+
                "��ʬ����Ʈ��\n",this_player() );

        call_out("die1",10,this_player() );
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        wuchang=new("/d/abyss/hell/monster/black_wuchang");
        wuchang->move("/d/abyss/hell/bridge");
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        return 1;
}

int die1()
{
        tell_object(this_player(),@C_LONG
���޳�˵��: ���䣬�Ҵ�����һ�����꣬���ȥͨ��һ����
���޳�תͷ����˵��: �ú�����������������κ��ž��������ˡ�
C_LONG
        );
        call_out("die2",10,this_player() );
        return 1;
}

int die2()
{
        tell_object(this_player(),@C_LONG
����˵��: ���������ã�ɭ�޵�����޵��У�������ȥ�ɣ�
����ץ������������һ����һ��������ת֮�ᣬ���ּ���һƬ��Ϥ�ľ��� ...
�����һ����ѣ���о��Լ��ֻص�����Ϥ�������
���ϱ��� ... ��ϡ�

C_LONG
                );


        this_player()->move_player("/d/noden/farwind/cemetery","SNEAK");
        this_player()->set("hit_points",10);
        this_player()->set("spell_points",1);
        if ( (string) this_player()->query("class") == "monk" )
        {
                this_player()->set("force_points",0 );
        }
        this_object()->remove();
        return 1;
}

