package mergeSort;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class MergeSort {
	private static int arrayLength = 1000;
	
	public static void main(String[] args) {

		String filePath = "random.txt";
		String fileName = "java merge sort.txt";
		
		int[] readArray;
		
		try {
			
			readArray = readInputFile(filePath);
			int[] sortedArray = mergeSort(readArray);
			writeSortedFile(fileName, sortedArray);
			
			System.out.println("DONE");
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

	
	private static int[] mergeSort(int[] readArray) {
		int length = readArray.length;
		
		if(length == 1){
			return readArray;
		}else{
			int[] temp1 = divideArrayFront(readArray);
			int[] temp2 = divideArrayBack(readArray);
			
			int[] arrayOne = mergeSort(temp1);
			int[] arrayTwo = mergeSort(temp2);
			
			return merge(arrayOne, arrayTwo);
		}
	}

	private static int[] divideArrayBack(int[] readArray) {
		int length = readArray.length;
		int[] result = new int[length/2];
		
		for(int i=0; i<result.length;i++){
			result[i] = readArray[i];
		}
		
		return result;
	}


	private static int[] divideArrayFront(int[] readArray) {
		int length = readArray.length;
		int[] result = new int[length-length/2];
		int start = length/2;
		
		for(int i=0; i<result.length; i++){
			result[i] = readArray[start+i];
		}
		
		return result;
	}


	private static int[] merge(int[] arrayOne, int[] arrayTwo) {
		int lengthOne = arrayOne.length;
		int lengthTwo = arrayTwo.length;
		
		int[] mergeResult = new int[lengthOne+lengthTwo];
		
		int i=0;
		int j=0;
		int x = 0;
		
		while(i<lengthOne && j<lengthTwo){
			if(arrayOne[i] > arrayTwo[j]){
				mergeResult[x] = arrayTwo[j];
				j++;
			}else{
				mergeResult[x] = arrayOne[i];
				i++;
			}
			x++;
		}
		
		while(i<lengthOne){
			mergeResult[x] = arrayOne[i];
			i++;
			x++;
		}
		
		while(j<lengthTwo){
			mergeResult[x] = arrayTwo[j];
			j++;
			x++;
		}
		
		return mergeResult;
	}


	private static void writeSortedFile(String fn, int[] array) throws IOException{
		File ouputFile = new File(fn);
		FileOutputStream fos = new FileOutputStream(ouputFile);
		OutputStreamWriter osw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(osw);
		
		for(int i=0; i<array.length; i++){
			bw.write(String.valueOf(array[i]));
			bw.newLine();
		}
		
		bw.close();
		osw.close();
		fos.close();
	}

	private static int[] readInputFile(String filePath) throws IOException   {
		File inputFile = new File(filePath);
		FileInputStream fis = new FileInputStream(inputFile);
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);
		
		int[] tempArray = new int[arrayLength];
		
		String s;
		int i=0;
		
		while((s = br.readLine())!=null){
			tempArray[i]= Integer.parseInt(s);
			i++;
		}
		
		br.close();
		isr.close();
		fis.close();
		
		return tempArray;
	}
}
