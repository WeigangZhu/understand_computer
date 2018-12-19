package main

import(
    "fmt"
    "github.com/360EntSecGroup-Skylar/excelize"
)

func main() {
    xlsx := excelize.NewFile()

    // Creat a new sheet
    index := xlsx.NewSheet("Sheet2")

    // Set value of a cell
    xlsx.SetCellValue("Sheet2", "A2", "Hello, world!")
    xlsx.SetCellValue("Sheet1", "B2", 1000)

    // Set active sheet of the workbook
    xlsx.SetActiveSheet(index)

    // Save xlsx file by the given path
    err := xlsx.SaveAs("./book1.xlsx")
    if err != nil {
        fmt.Println(err)
    }

}
