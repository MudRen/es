#include <mudlib.h>

inherit ROOM;

int view_note() ;
void create()
{
	::create();
        set_short("Healer's upper room", "��ҽ��������");
	set_long(
@C_LONG_DESCRIPTION
�������ҽ�߶�����ׯ�����µ�ʥ�أ���Ϊ��������Ҫ���԰�����
�ط�����ǽ�ǵ��������м������䲻����ͬ����ҽ������ϰ����֮����
����ǽ�ϵĸ�ʾ(NOTE)���Եõ����������������ȷ������
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"note": "view_note" 
 		           ]) );
	set( "exits", ([ 
		"down" : "/d/healer/building/healer_inner"
		       ]) );
	
	reset();
}

void init()
{
   add_action("do_study","study") ;
   add_action("do_upgrade","upgrade") ;
}

int do_study(string str)
{
    int skill ;

    if(!str || str != "force")
      return view_note() ;
   
    if(this_player()->query("dou-in"))
       return notify_fail("����ѧϰ���߶εĵ������Ļ����� UPGRADE ���ָ��\n") ;

    skill = this_player()->query_skill("concentrate") ;
    
    if( !skill || skill <35 )
       return notify_fail("��һ�������ž���վ����,������˵ר�������ˡ�\n") ;

    if((int)this_player()->query_exp_stock() < 1000)
        return notify_fail("��ľ���ֵ��������������\n") ;
            
    this_player()->set("dou-in",1) ;
    this_player()->gain_experience( -1000 );                
    write("����������һ������֮�ϡ��۹۱�,�ǹ���,���ص���.....\n"
          "��е���֫��Ѩ�й�ů������������ĵ��\n") ;            
                
    return 1 ;
}

int do_upgrade(string str)
{
    int lev,skill,exp ;

    if(!str || str != "force")
      return view_note() ;
    
    lev = this_player()->query("dou-in") ; 
        
    if( !(lev) || lev == 0 )
       return notify_fail("����ѧϰ�������Ļ����� STUDY ���ָ��\n") ;   

    exp = (lev+1)*(lev+1)*(lev+1)*1000 ;

    skill = this_player()->query_skill("concentrate") ;    

    if( (int)this_player()->query_exp_stock() < exp ) 
      {
        return notify_fail("�㻹��Ҫ"+exp+"�㾭��ֵ������������\n") ;   
       }
              
    if( lev == 5 || skill < 30 + lev * 12 )   
       return notify_fail
         ("����������һ������֮�ϡ��۹۱�,�ǹ���,���ص���.....\n"
          "��е���֫��Ѩ�й�ů������������ĵ��\n"
          "������������ڵ�����û��ʲ��仯��\n") ;            

    write("����������һ������֮�ϡ��۹۱�,�ǹ���,���ص���.....\n"
          "��е���֫��Ѩ�й�ů������������ĵ��\n"
          "������,��������ڵ�������ǰ���ࡣ\n") ;            

    this_player()->gain_experience( -exp );
    this_player()->add("dou-in",1) ;
      
    return 1 ;
}


int view_note()
{
  write(
"  ���������������������, ����ֻ�п���רע�ľ�����ܽ��䵼�����⡣\n"
"��ѧϰ����(study)������(upgrade)����������, �������ܷ��о�����\n"
"���ԵĹ�ϵ��\n\n"
"  ��ϰ��������:\n"
"         ѧϰ����       :  study force \n"
"         ����������     :  upgrade force \n\n"  )  ;

  return 1 ;
}



