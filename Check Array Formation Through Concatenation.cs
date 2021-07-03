public class Solution {
    public bool CanFormArray(int[] arr, int[][] pieces) {
        var set = new HashSet<string>();
        for(int i=0;i<pieces.Length;i++){
            set.Add(GetKey(pieces[i]));
        }
        
        var strList = new List<int>();
        var str = "";
        for(int i=0;i<arr.Length;i++){
            strList.Add(arr[i]);
            str = GetKey(strList.ToArray());
            if(set.Contains(str)){                
                strList.Clear();
            }            
        }
        
        return strList.Count()==0;
    }
    
    private string GetKey(int[] piece){
        return string.Join(":",piece);
    }
}