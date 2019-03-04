#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  ���������Ϊ���ε������� realname ���ǳɹ��ı�ʶ�ᴫ�ص�����     
        
	set_short("@@query_c_name");    
        
        set("c_realname","����ݮ��");         // ��ұ��ϳɹ����ص�����
        set("realname","swamp berry");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","swamp_berry.c") ;     //���������Ķ�������������
        set("herb_path","/d/healer/reagent/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",15) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",4);                    //���ܲɼ���
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;
   
  if (this_player()->query_stat("int") < 10 ) {
    set_name("A plant","С��");
    set_long("��������С��ǰǰ���ῴ�˰���, ��춵õ�һ������--��������ɶ\n"
             "�ر�ġ�\n");
    set( "id" , ({ "plant","tree"}) );
    return "С��";
  }  
  else if ( ok==1 ) {
    set_name("swamp berry","����ݮ��");
    set_long("��������ϸ�����Ľ��, ���ж����ǿ�����ݮ��(swamp berry),\n"
             "�������ҩ��, ��������(dig)һ���ȥ��\n");
    set( "id" , ({ "plant","tree","berry","swamp berry"}) );
    return "����ݮ��";
  }  
  else {
    set_name("a short life plant","һ�����ݱ�ֲ��");        
    set_long( "�������ڹ�������α��е�����֪ʶ, ���ж�����һ��һ�����ݱ�ֲ��, \n"
              "������ȷ������, ����Ҫ��һ���ı�ʶ��\n");
    set( "id" , ({ "plant","tree"}) );
    return "һ�����ݱ�ֲ��";
  }   
}      
