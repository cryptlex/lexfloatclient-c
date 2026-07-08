<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.dropBtn = New System.Windows.Forms.Button()
        Me.leaseBtn = New System.Windows.Forms.Button()
        Me.statusLabel = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'dropBtn
        '
        Me.dropBtn.Location = New System.Drawing.Point(236, 48)
        Me.dropBtn.Name = "dropBtn"
        Me.dropBtn.Size = New System.Drawing.Size(92, 23)
        Me.dropBtn.TabIndex = 0
        Me.dropBtn.Text = "Drop License"
        Me.dropBtn.UseVisualStyleBackColor = True
        '
        'leaseBtn
        '
        Me.leaseBtn.Location = New System.Drawing.Point(32, 48)
        Me.leaseBtn.Name = "leaseBtn"
        Me.leaseBtn.Size = New System.Drawing.Size(101, 23)
        Me.leaseBtn.TabIndex = 1
        Me.leaseBtn.Text = "Lease License"
        Me.leaseBtn.UseVisualStyleBackColor = True
        '
        'statusLabel
        '
        Me.statusLabel.AutoSize = True
        Me.statusLabel.Location = New System.Drawing.Point(29, 114)
        Me.statusLabel.Name = "statusLabel"
        Me.statusLabel.Size = New System.Drawing.Size(40, 13)
        Me.statusLabel.TabIndex = 2
        Me.statusLabel.Text = "Status:"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(362, 158)
        Me.Controls.Add(Me.statusLabel)
        Me.Controls.Add(Me.leaseBtn)
        Me.Controls.Add(Me.dropBtn)
        Me.Name = "Form1"
        Me.Text = "Float Client"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents dropBtn As Button
    Friend WithEvents leaseBtn As Button
    Friend WithEvents statusLabel As Label
End Class
