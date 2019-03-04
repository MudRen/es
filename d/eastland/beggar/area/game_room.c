#include "/d/eastland/beggar/dony.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "�����须�ķ�" );
        set_long(@C_LONG
������֮���ǡ�н���塻�������Ķķ�,����Ŀ����е����, ߺ�����ر�
���ڴ���,ƽʱ����û��ʲ��ط�����ȥ����,Ҳû��ʲ�ᶫ�������ֵ�,ֻ��
���������һ������׬׬���, ��Ҳ���������������������ม������׻��ú�:
��ʮ���Ǿ��䡻,��Ӧ�ò�������ɵ�ɡ�ǽ������һ��ֽ��
C_LONG
        );
        set( "c_item_desc", ([
            "paper" :@C_LONG
�����������д��:
        ���ķ��Ķķ���һ�ο��������ӵķ�ʽ;����Ҫ ( bet number type )
        ��: bet 100 silver ��ʾ��һ��Ѻ 100 �����ҵĳ���,�� ( select 
        number number number ) ��: select 2 3 5 ��ʾ��Ѻ 2 3 5 ������
        ���֡��������ֶ���ȫ���������� 200 ���ĳ���;����֮���û���ˡ� 
C_LONG
        ]) );
                                         
        set("exits",([
             "west":DBEGGAR"north1"
        ]) );
        set("objects", ([
             "merchant":DMONSTER"ch_waiter"
        ]) );     
        reset();
}
void init()
{
      add_action("do_bet","bet" );
      add_action("do_select","select");
}

int do_bet(string arg)
{
   object who;
   string type,weal_type;
   int num,weal;
                           
   if ( !arg || arg=="" || sscanf( arg, "%d %s", num, type)!=2 )
       return notify_fail("��ҪѺ���٣�ʲ�������Ǯ��\n");
   if ( type!="silver" )
       return notify_fail("����������Ϊ��λ,лл��\n");
   who=this_player();
   weal=who->query("wealth/silver");                        
   if ( num > weal )
       return notify_fail("�Բ���,������������Ǯ����ม�\n"); 
   if ( num > 5000 )
       return notify_fail("�Բ���,СС�ĵ����벻Ҫ���� 5000 ���ҡ�\n");
   who->set_temp("money_bet",num);
   tell_object(who,
      "��Ѻ "+num+" �����ҡ�\n");
   return 1;    
}
int do_select(string arg)
{
   object me;
   int num1,num2,num3,number1,number2,number3,bet_money;
   
   if ( !arg || arg=="" || sscanf( arg, "%d %d %d", num1, num2, num3)!=3 )
       return notify_fail("�㵽��ҪѺ�Ǽ�������ѽ��\n");
          
   if ( num1>6 || num1<1 || num2>6 || num2<1 || num3>6 || num3<1 ) 
       return notify_fail("���ǲ��������ͷ,�����в���С����������������?��!\n");
   
   me=this_player();
   bet_money=me->query_temp("money_bet");

   if ( !bet_money )
       return notify_fail("�Բ���,�����ѺһЩ���롣\n");
   if ( bet_money > (me->query("wealth/silver")) )
       return notify_fail("�Բ���,������������Ǯ����Ӵ��\n");
   
   tell_object(me,
      "������һ��Ѻ�� "+num1+" "+num2+" "+num3+" ���������֡�\n");
   me->add("wealth/silver",-bet_money);
   number1=random(6)+1;
   number2=random(6)+1;
   number3=random(6)+1;        

   tell_object(me,
      "�������Ľ���� "+number1+" "+number2+" "+number3+" �����֡�");
   if ( ( num1==number1 ) && 
        ( num2==number2 ) && 
        ( num3==number3 ) ) {
         me->add("wealth/silver",201*bet_money);
         tell_object(me,"PERFECT!!��Ȼ��ȫ�������,��������!!\n");
         tell_room(this_object(),                
"��մ���һ��������̾Ϣ��,"+me->query("c_name")+"�����˶��ٱ��Ľ���!!\n",me);
   } else
      tell_object(me,"��ϧ,û���С�\n"); 
   return 1;                     
}
