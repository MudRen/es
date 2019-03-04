#include "iigima.h"

inherit ROOM;

int adv;

void create()
{

        ::create();
        set_short( "desk","��̳");
        set_long(
@C_LONG
��������㿴��һ��ټ��ļ�̳�����ķ��ε�ʯש���ɵļ�̳��
�����ɰ˸�������֧������̳�ķ��ζ��̣��������������������ߵ�ʯ
��(statue)���ţ�һ��̶��ļ����������ǰ���������������������
�������¸ҵ�����������ǰ����
C_LONG
        );
        set( "light",1 );
        set( "exits", ([
                     "northwest": DROW"r29",
                    
                     "south": DROW"r33",
        ]) );
        set("c_item_desc",([
              "statue":
@C_LONG
�ţ����ô����������������ģ����������צ�ƺ�Ҫһ�������㣡
�ף�����Ļ����и�С��(hole)�������ֵֹ�....
C_LONG
,             "hole":
@C_LONG
���С��������״�ֵֹģ����񱻸�ʴ�ĺۼ�������ĳ�ֿ�����
������Է���(put)ʲ�ᶫ��....
C_LONG
     ])); 
        reset();
}

void init()
{
   add_action("do_put","put");
}

int do_put(string str)
{
        object ob,player;
        string scale;
        player = this_player();

   if( !str || str != "scale into hole" ) {
        write( "��Ҫ��ɶ?\n" );
        return 1;
     }
        ob = present("scale",player);
   if( !ob ) {
        write( "������û�����ۣ�\n" );
        return 1;
     }
   if( adv ) {
        tell_object( player,
                    "������۷Ž���̳�ϵ�һ��С������һ����˲ʱ���������������ɿ��ˣ�\n"
                    "\n"
                    "��������������������Ĺֽ������桫�ÿ��¡�\n"
                    );
        add("exits",(["northeast":DROW"r30"]));
	new(DRO"teeder")->move(this_object());
   ob->remove();
                    adv = 0;
                return 1; 
     }
        else tell_object( player,
                    "����������ۣ�����ʲ���¶�û�з�����\n" );
   ob->remove();
   return 1;
}

void reset()
{
   room::reset();
   adv = 1;
   delete( "exits/northeast" );
}
