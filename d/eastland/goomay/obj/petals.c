#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("petals", "����");
        set_short("petals", "����");
        set_long(@LONG
This is a lot of petals . sprinkle it at somebody will bring fun.
LONG
, @CLONG
��������ʱ�õĻ��꣬��������(sprinkle)�����ʱ�������γ�һ��������ͼ����\n
CLONG
        );
        set("unit", "��");
        set( "weight", 0 );
        set ("value", ({ 10, "silver" }) );
        seteuid( getuid() );
}

void init()
{
        add_action("do_use","sprinkle");
}

int do_use(string arg)
{
        string cmsg, cmsg1, cmsg2;
        object target;

        if ( !arg || arg=="" )
	return  notify_fail( 
                "�����˭������ ��  uasge : sprinkle <who> \n" );

        target = present( arg , environment(this_player() )) ;
	if ( !target )
	return notify_fail( "����û������ˡ�\n" );

        if (target == this_player()) 
                {
                   write(
                        "��ѻ���������գ���ʱ�������һ���ꡣ\n" );
                  tell_room( environment(this_player()), 
			             target->query("c_name") +
                         "��һ�ѻ���������գ���ʱ����һ���ͷ׻��꣬ ������е�����\n",
			  this_player() );  
                  remove() ;
                  return 1 ;       
                }
        else {
                cmsg = "�㽫������"+
                        target->query("c_name") +
                        "������һ������ʱ����һ�������һ���ӳ���ͼ����\n";
                cmsg1 = this_player()->query("c_name")+
                        "����������"+
                        target->query("c_name") +
                        "�����ϣ���ʱ����һ�������һ���ӳ���ͼ����\n";
                cmsg2 = this_player()->query("c_name")+
                        "��һ�ѻ����������������ͷ׵Ļ������У�����������ˡ�\n";

                tell_object( this_player(), cmsg );
                tell_room( environment(this_player()), cmsg1 ,
                        ({ this_player(), target }) );
                tell_object( target, cmsg2 );

                remove();
                return 1;
        }
}
