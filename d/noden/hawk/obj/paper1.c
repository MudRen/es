
#include <mudlib.h>

inherit OBJECT;
void create()
{
        set_name("paper", "СֽƬ");
        add( "id", ({ "paper" }) );
        set_short( "СֽƬ" );
        set("long","����ֽ�Ѿ������Ǭ�ˣ����������(read)������֡�\n");
        set( "weight", 3 );
        set( "unit", "��" );
}

void init()
{
        add_action("to_read","read");
}

int to_read()
{
        tell_room(environment(),(string)this_player()->query("c_name")
                +"�������е�ֽƬ�۾�����Ķ���������һ����һ��ף���֪��"
		+"�����ˡ�\n",this_player() );
        tell_object(this_player(),@LONG
������ֽƬ�۾�����Ķ�������������д����
ʰ������ŵ����ߣ����������������ά�࣬ϣ��������һ�����ߣ���
Ϊ�ҽ���ҵ����⡣
����ţ����ҵ����飬ϣ�����㷢�ֵ�ʱ���ҵĹ��磭���֮�ǣ���
Ȼ��Ȼ��Ʈ��������У��ҵ�������Ȼ������һ���������ǣ����
֮�������ٵ�Σ����Ȼ���ڣ�ǿ��ĵ��˻��ӵ��������������˵ĲƸ�
�����֮�����ص�����....
���ߣ��ҿ����㣬��ŵ�������ҵ��ҵ�Ĺ��ȡ���ҵĽ�ָ���Դ�Ϊ����
�����֮��Ѱ�Ұ���˿���ҵİ��ޣ�������Э���㣬�����˽�һ������
��֪���ģ�����Ϊ�Һú��չ˰���˿�����������ܵ��ҵĵ����ǵ��˺�

��л��....����....
                                        ά��
LONG
        );
        return 1;
}

