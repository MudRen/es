#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_short("@@query_c_name");    
        
        set("c_realname","ѩ��");         // ��ұ��ϳɹ����ص�����
        set("realname","snow lotus");
	
   	set("unit","��");                     // ��,��,��.�����

   	set("weight", 50000);                 // ֻҪ��֤��Ұ᲻���ͺ���

   	set("value", ({0, "silver"}) );       // Ұ��������Ȼ��ֵǮ��
      
        set("herb_file","snow_lotus.c") ;     //���������Ķ�������������
        set("herb_path","/d/healer/reagent/");   //���������Ķ�����Ŀ¼
                                              //�ǵ�������Ŀ¼
                                              //default �� /d/healer/plant
                                                
        set("skill_require",90) ;             //Ҫ�ɹ���ʶ����ֲ������֮����
        set("purified",1);                    //���ܲɼ���
       
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
    set("id",({"plant","tree"}) );
    set_name("a plant","С��");
    set_long("��������С��ǰǰ���ῴ�˰���, ��춵õ�һ������--��������ɶ\n"
             "�ر�ġ�\n");
    return "С��";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","lotus","snow lotus"}) );
    set_name("snow lotus","ѩ��");
    set_long("��������ϸ�����Ľ��, ���ж����Ǽ��ټ���ѩ��(snow lotus),\n"
             "�������ҩ��, ��������(dig)һ���ȥ��\n");
    return "ѩ��";
  }  
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","�������ݱ�ֲ��");
    set_long("�������ڹ�������α��е�����֪ʶ, ���ж�����һ�ֶ������ݱ�ֲ��, \n"
             "������ȷ������, ����Ҫ��һ���ı�ʶ��\n");
    return "�������ݱ�ֲ��";
  }
}      


