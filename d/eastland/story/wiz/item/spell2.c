#include <mudlib.h>
inherit OBJECT;

void create()     
{
	set("short", "@@query_short");
	set("long", "@@query_long");
 	set_name( "wonderful-spell", "���������" );
        add("id",({"wonderful"}));
	set( "unit", "��" );
	set("weight", 10);
	set("value", ({ 5, "silver" }));
	set("fuel", 3600); 
}


void init()
{
	add_action("cast_me", "cast-me");
	add_action("uncast_me", "uncast-me");
}

int cast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
	 return notify_fail("���������ʩΪ��\n");
     if ( !arg || arg!="wonderful" ) 
	 return notify_fail("Syntax <cast-me wonderful>\n");
     if( query("wonderful_used") ) 
	 return notify_fail( "���������������ʩչ��\n");
     if( player->query_temp("wonderful_spell") )
         return notify_fail("�㼺��ʩչ����������ˡ�\n");         
     write("�㿪ʼʩչ����������������Լ����һ�ų�����\n");
     set("wonderful_used", 1);
     set("prevent_get",1);
     set("prevent_drop",1);
     set("prevent_insert",1);
     player->set_temp("wonderful_spell",1);
     call_out("burn_out",query("fuel"));
     return 1;
}

int uncast_me(string arg)
{
     object player;
     player=environment();
     if ( !living(player) )
         return notify_fail("���������ʩΪ��\n");
     if ( !arg || arg!="wonderful" )
             return notify_fail("Syntax <uncast-me wonderful>\n");
     if( !query("wonderful_used") )
	 return notify_fail( "�������������δʩչ��������ֹ��\n");
	                 
     write("����ʱ����ֹ�����������ʩչ�����ԭ����ģ����\n");
     set("wonderful_used", 0);
     set("prevent_get",0);
     set("prevent_drop",0);
     set("prevent_insert",0);
     player->delete_temp("wonderful_spell");
     set("fuel", remove_call_out("burn_out"));
     return 1;
}
void burn_out()
{
     object owner;

     owner = environment(); 
     if( living(owner) )
        tell_object( owner,"�������������Դ�Ѿ��ľ��ˣ���\n");
     owner->delete_temp("wonderful_spell");
     this_object()->remove();
}
string query_short()
{
     if(query("fuel"))
        return sprintf("���������%s", (query("wonderful_used") ? " (ʹ����)" : "") );
}

string query_long()
{
     if(query("fuel"))
	return (@LONG
����������ǽ�ʯ���˶����о��������ε����ʵ��ĵö����ġ���������������
�����ѵ����ٱ�ɿ����еĳ��������ڿռ����һ���Լ��ķ���������ƭ���ˣ���
�ﵽ�������ѵĹ��á�����������о��Ĳ���ȫ������ֻ�ܶ�ĳЩ�ض��Ĺ����ʹ
�á�ʹ��ʱ����ֻҪ��(��cast-me wonderful��)���Ϳ����ˣ��������мǣ�����
��ʹ�õ�ʱЧ���������ֻ�衡( uncast-me wonderful )���Ϳ����ˡ��ݽ�ʯ
���˵Ĺ��ƣ�ȫ���а��ʱ����ʱЧ��
LONG
     );
}
