#include "iigima.h"

inherit ROOM;


int stone = 1;
void create()
{

        ::create();
        set_short( "snake temple","�������");
        set_long(

@C_LONG
�ۡ�����������Ȼ�����������ף��������е�ʯ�񣬻���
�Ļ������ѵ����ѣ����������ʯ��������÷�����������ʱ����
�̶��Ĺֽ�������֪����ʲ�������������һ����������ͷ������
�ոյ������ƺ��Ѿ����־�����û�ˣ����ض��Ǻ����Լ����ĵ���Ƥ
����������Ѿ��ܵ����飡
C_LONG
        );

        set( "light",0 );
        set( "exits", ([
                     "west": DROW"r30",
        ]) );
        set("objects", ([
                "snake": DRO"s8",      
        ]) );
        set( "search_desc", ([ "skin" : "@@search_skin" ]) );
        reset();
}
string search_skin()
{
        object obj;
        if( !stone || present("stone", this_object()) ) return
                "���Ǭ����Ƥһ���ŷ�����ȥ����û�з����κζ�����\n";
   if( present("eight tail snake",this_object()) )
   return "��᪴������ڹ�����! ����æ�����޷���Ѱ!\n";
        obj = new( OBJ "stone" );
        obj->move( this_object() );
        stone = 0;
        return "������Ƥ���з�����һ����˸�������ʯͷ��\n";
}
